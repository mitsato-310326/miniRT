# macOS での minilibx トラブル完全まとめ

## 背景：minilibx の種類

42 school の minilibx には大きく3種類ある。

| 種類 | 形式 | ファイル | 対象OS |
|------|------|---------|--------|
| Linux版 | `.a` | `.c` + X11 | Linux |
| macOS OpenGL版 | `.a` | `.c` + `.m` (Objective-C) | macOS |
| macOS Metal版 | `.dylib` | `.c` + `.swift` | macOS (新しめ) |

**今回の教訓：元々あった OpenGL版（`.m` ファイル群 + `libmlx.a`）が最も安定している。**

---

## 問題1：`-lXext -lX11` エラー

### 症状
```
ld: library 'Xext' not found
```

### 原因
Makefile のリンクフラグが Linux 用（X11）のままになっていた。macOS には X11 がデフォルトで存在しない。

### 解決
```makefile
# ❌ Linux用（macOSでは動かない）
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# ✅ macOS OpenGL版
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

# ✅ macOS Metal版（使う場合）
MLX_FLAGS = mlx/libmlx.dylib -framework Metal -framework MetalKit \
            -framework AppKit -framework Foundation
```

---

## 問題2：`libmlx.a` vs `mlx.a`（ファイル名の不一致）

### 症状
make が mlx をビルドしようとして失敗する。

### 原因
Makefile の `MLX_LIB = mlx/mlx.a` に対して、実際のライブラリは `mlx/libmlx.a`。  
`MLX_LIB` はビルドターゲットとして使われるため、名前が違うと常に「存在しない→再ビルド」となる。

### 解決
```makefile
MLX_LIB = mlx/libmlx.a  # 実際のファイル名に合わせる
```

---

## 問題3：Metal版 Swift の並列ビルドクラッシュ

### 症状
```
Fatal error: multiple producers for output mlx_image.swiftmodule
```

### 原因
Metal版 mlx の Makefile が同じ `.swift` ファイルから `.o` と `.swiftmodule` を**別々のルール**で生成しようとする。swiftc はどちらのルールでも両方を副産物として作るため、競合してクラッシュする。

`-j1`（シングルスレッド）にしても直らない。これは **Makefile の構造的バグ**。

### 解決（mlx を編集しない前提）
main Makefile 側で mlx の Makefile を使わず、swiftc を手動で順番に呼ぶ：

```makefile
# モジュールファイルを1つずつコンパイル（.o と .swiftmodule を同時生成）
swiftc -I. -parse-as-library -c \
    -emit-module -module-name mlx_image -emit-module-path mlx_image.swiftmodule \
    mlx_image.swift -o mlx_image.o
# ... window, init も同様 ...
# 最後に interface.swift をコンパイル
swiftc -I. -parse-as-library -c interface.swift -o interface.o
```

---

## 問題4：Swift の型互換性エラー

### 症状
```
error: cannot convert value of type 'UInt32' to expected argument type 'boolean_t' (aka 'Int32')
```

### 原因
`minilibx_macos_metal.tgz`（2020年版）の `interface.swift` が古い macOS SDK 向けに書かれており、現在の SDK では `boolean_t` の型定義が変わっている（`UInt32` → `Int32`）。

### 解決（mlx 本体を編集しない場合）
`sed` で一時ファイルを作ってコンパイル：

```makefile
sed 's/CGAssociateMouseAndMouseCursorPosition(UInt32(1))/CGAssociateMouseAndMouseCursorPosition(Int32(1))/' \
    interface.swift > /tmp/_mlx_interface.swift
swiftc -I. -parse-as-library -c /tmp/_mlx_interface.swift -o interface.o
```

---

## 問題5：`dylib` の `install name` 問題

### 症状
```
dyld: Library not loaded: libmlx.dylib
```

### 原因
`swiftc -emit-library -o libmlx.dylib` でビルドすると、dylib 内部の `install name`（自分のパスの情報）が `libmlx.dylib`（相対パスなし）になる。rpath を設定しても、install name が `@rpath/libmlx.dylib` でないと rpath 検索が使われない。

### 解決
ビルド後に `install_name_tool` で修正する：

```makefile
install_name_tool -id @executable_path/mlx/libmlx.dylib mlx/libmlx.dylib
```

または、リンク時に install name を指定する：

```
swiftc ... -Xlinker -install_name -Xlinker @rpath/libmlx.dylib
```

### `.a`（静的ライブラリ）との違い

| | `.a` 静的ライブラリ | `.dylib` 動的ライブラリ |
|--|--|--|
| 実行時の依存 | なし（バイナリに埋め込み） | あり（実行時にロード） |
| install name | 不要 | 必要 |
| rpath | 不要 | 必要 |
| ファイルの場所 | どこでもOK | 実行時に見つかる場所に必要 |

**ゆえに `.a` の方がシンプル。** miniRT には OpenGL版（`.a`）を使うのが楽。

---

## 最終的な正解構成（macOS）

```makefile
MLX_DIR = mlx/
MLX_LIB = mlx/libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

$(MLX_LIB):
    @if [ ! -d "$(MLX_DIR)" ]; then \
        git clone https://github.com/mario8705/minilibx.git $(MLX_DIR); \
    fi
    @$(MAKE) -C $(MLX_DIR)
```

使用する mlx：`mario8705/minilibx`（42の macOS OpenGL版の安定フォーク）

---

## 判断チートシート

```
エラー: lXext / lX11 not found
  → MLX_FLAGS から X11 を削除、-framework OpenGL -framework AppKit に変更

エラー: library 'mlx' not found
  → MLX_LIB のファイル名を ls mlx/ で確認（libmlx.a か mlx.a か）

エラー: multiple producers for swiftmodule
  → Metal版の Makefile バグ。OpenGL版に切り替えるのが最善

エラー: dyld Library not loaded
  → install_name_tool -id @executable_path/... で install name を修正

実行時セグフォ（mlx 側）
  → mlx_new_window に NULL タイトルを渡していないか確認
  → mlx_init() の戻り値の NULL チェックが main 側にあるか確認
```
