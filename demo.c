
void	my_pixel_put(char *data, int x, int y, int color)
{
	int	offset;

	x += WIDTH / 2;
	y += HEIGHT / 2;
	x -= diameter(0, 0, 0) * (left_max(2, 0) + right_max(0, 0)) / 2;
	y += diameter(0, 0, 0) * (bottom_max(2, 0) + top_max(0, 0)) / 2;
	if (!(x > 0 && x < WIDTH && y > 0 && y < HEIGHT))
		return ;
	offset = (y * WIDTH + x) * 4;
	data[offset + 0] = color & 0xFF;
	data[offset + 1] = (color >> 8) & 0xFF;
	data[offset + 2] = (color >> 16) & 0xFF;
	data[offset + 3] = 0;
}

int	lerp_color(int c1, int c2, double t)
{
	int	rgb[3];
	int	rgb2[3];
	int	r;
	int	g;
	int	b;

	rgb[0] = (c1 >> 16) & 0xFF;
	rgb[1] = (c1 >> 8) & 0xFF;
	rgb[2] = c1 & 0xFF;
	rgb2[0] = (c2 >> 16) & 0xFF;
	rgb2[1] = (c2 >> 8) & 0xFF;
	rgb2[2] = c2 & 0xFF;
	r = (int)(rgb[0] * (1.0 - t) + rgb2[0] * t);
	g = (int)(rgb[1] * (1.0 - t) + rgb2[1] * t);
	b = (int)(rgb[2] * (1.0 - t) + rgb2[2] * t);
	return ((r << 16) | (g << 8) | b);
}

int	set_color(int condition, int start, int end, int now)
{
	double	t;
	int		color_origin;
	int		color;
	int		tmp;

	color_origin = 0xFFFFFF;
	color = 0xFFFFFF;
	t = (double)(now - start) / (double)(end - start);
	if (set_corrent_color(0, NULL, 0, 0))
		color_origin = set_corrent_color(0, NULL, 0, 0)->color;
	if (condition & (1 << 0) && set_col_color(0, NULL, 0, 0))
		color = set_col_color(0, NULL, 0, 0)->color;
	else if (!(condition & (1 << 0)) && set_prev_color(0, NULL, 0, 0))
		color = set_prev_color(0, NULL, 0, 0)->color;
	if ((condition & (1 << 0)) ^ !(condition & (1 << 1)))
	{
		tmp = color_origin;
		color_origin = color;
		color = tmp;
	}
	return (lerp_color(color_origin, color, t));
}
