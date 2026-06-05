# miniRT

A minimal ray tracer built in C.

![miniRT screenshot](./screenshots/screenshot.png)

---

## Overview

miniRTは、C言語で実装したミニマルなレイトレーサーです。
光の反射・屈折・陰影などのレンダリングをゼロから実装しています。

> ✏️ *このセクションはプロジェクトの実態に合わせて書き換えてください。*

---

## Features

- リアルタイムレンダリング
- キーボードによるカメラ操作
- （その他の特徴があれば追記してください）
---

## Requirements

- Linux
- make
- cc（gccまたはclang）
- （その他の依存ライブラリがあれば追記してください）
---

## Getting Started

### Build

```bash
make
```

### Run

```bash
./miniRT
```

---

## Controls

| キー | 動作 |
|------|------|
| `↑` `↓` `←` `→` | 移動 |
| `Shift` + 矢印キー | 移動（高速 / 別軸） |
| `ESC` | 終了 |
| 画面端の ✕ ボタン | 終了 |
