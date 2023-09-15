#include "../includes/cub3d.h"

int ft_get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_create_sky(t_vars *vars, mlx_image_t *img, int size2, int size, unsigned int col)
{
	int start_draw_x = 0;
	int start_draw_y = 0;
	unsigned int start_color = col;
	// int size_loc = size/2;
	while (start_draw_x < WIDTH)
	{
		start_draw_y = 0;
		while(start_draw_y < HEIGHT)
		{
			if (start_draw_y > (HEIGHT) / 2)
				col = ft_get_rgba(100,100,100,100);
			else
				col = start_color;
			mlx_put_pixel(img, start_draw_x, start_draw_y, col);
			start_draw_y++;
		}
		// mlx_put_pixel(img, start_draw_x, start_draw_x, 0xFFFFFFFF);
		start_draw_x++;
	}
}