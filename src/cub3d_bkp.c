/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:37:50 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/12 11:02:50 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



u_int32_t ft_get_text_col(t_vars *vars)
{
	static int num = 0;
	static int c = 24;
	static int c2 = 4;
	u_int32_t col;


	col = ft_get_rgba(vars->texture->pixels[num], vars->texture->pixels[num + 1], vars->texture->pixels[num +2],  vars->texture->pixels[num + 3]);
	num+=4;
	if (num >= vars->texture->width * vars->texture->height)
		num = 0;
	return(col);
}
void ft_create_image(t_vars *vars, mlx_image_t *img, int size, int size2, unsigned int col)
{
	int start_draw_x = 0;
	int start_draw_y = 200;
	int h = HEIGHT  - 100;
	int w = WIDTH;
	// int size_loc = size/2;
	int r = 100;
	int g = 200;
	int b = 150;
	int frst_part_x = 1;
	int frst_part_y = 1;
	int num = 0;
	int coef = 0;
	// col = ft_get_rgba(vars->texture->pixels[num], vars->texture->pixels[num + 1], vars->texture->pixels[num +2],  vars->texture->pixels[num + 3]);

	while( start_draw_x < size)
	{
		num+=4 * coef;
		frst_part_y = start_draw_x;
		while (frst_part_y < h - 1)
		{
			// printf("start_draw_y = %d\n", frst_part_y);
			mlx_put_pixel(img, start_draw_x, frst_part_y++, ft_get_rgba(vars->texture->pixels[num], vars->texture->pixels[num + 1], vars->texture->pixels[num +2],  vars->texture->pixels[num + 3]));
			num+=4;
		}
		// printf("start_draw_x = %d\n", start_draw_x);
		// printf("h= %d\n", h);
		coef++;
		h--;
		start_draw_x++;
	}
	frst_part_x = start_draw_x;
	col = ft_get_rgba(255, 255, 255, 255);
	while (start_draw_x < WIDTH)
	{
		start_draw_y = frst_part_x;
		while(start_draw_y < frst_part_y)
		{
			mlx_put_pixel(img, start_draw_x, start_draw_y, ft_get_text_col(vars));
			start_draw_y++;

		}
		col = ft_get_rgba(r, g, b, 255);

		start_draw_x++;
	}





			// r++;
		// 	if (r == 255 || g == 200 || b == 255)
		// 	{
		// 		if (r == 255)
		// 		{
		// 			r = 0;
		// 			g++;
		// 		}
		// 		else if (g == 200)
		// 		{
		// 			g = 0;
		// 			b++;
		// 		}
		// 		else if (b == 255)
		// 		{
		// 			r = 0;
		// 			g = 0;
		// 			b = 0;
		// 		}
		// 	}
		// }
		// mlx_put_pixel(img, start_draw_x, start_draw_x, 0xFFFFFFFF);
}

void ft_hook(void* param)
{
	t_vars *vars;
	vars = param;
	int static jump = 0;
	int static sit = 0;
	if (jump)
	{
		vars->texture2img->instances[0].y -= 60;
		vars->sky->instances[0].y -= 60;
		jump = 0;
	}
	if (sit)
	{
		vars->texture2img->instances[0].y += 20;
		vars->sky->instances[0].y += 20;
		sit = 0;
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT_SHIFT))
	{
		sit = 1;
		vars->texture2img->instances[0].y -= 20;
		vars->sky->instances[0].y -= 20;
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_SPACE))
	{
		jump = 1;
		vars->texture2img->instances[0].y += 60;
		vars->sky->instances[0].y += 60;
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
	{
		static int count = 0;
		if (count == 20)
			count = 0;
		vars->texture2img->instances[0].x -= SPEEX;
		// vars->gun->instances[0].x+= 3;
		mlx_delete_image(vars->mlx, vars->gun);
		vars->gun = mlx_texture_to_image(vars->mlx, vars->gun_text);
		mlx_resize_image(vars->gun, vars->gun->width + count, vars->gun->height + count);
		mlx_image_to_window(vars->mlx, vars->gun, 1024 + count, 800 - count);
		count++;
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
		// vars->gun->instances[0].x-= 3;
	{
		static int count = 0;
		if (count == 20)
			count = 0;
		vars->texture2img->instances[0].x += SPEEX;
		mlx_delete_image(vars->mlx, vars->gun);
		vars->gun = mlx_texture_to_image(vars->mlx, vars->gun_text);
		mlx_resize_image(vars->gun, vars->gun->width + count, vars->gun->height + count);
		mlx_image_to_window(vars->mlx, vars->gun, 1024 + count, 800 - count);
		count++;
	}
		// mlx_resize_image(vars->texture2img, WIDTH-5, HEIGHT - 1);

	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
	{
		vars->size_x += SPEEX;
		vars->size_y+=SPEEY;
		vars->save_pos_x = vars->texture2img->instances[0].x;
		vars->save_pos_y = vars->texture2img->instances[0].y;
		mlx_delete_image(vars->mlx, vars->texture2img);
		vars->texture2img = mlx_texture_to_image(vars->mlx, vars->texture);
		// vars->texture2img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
		mlx_resize_image(vars->texture2img, vars->size_x, vars->size_y);

		// ft_create_image(vars, vars->texture2img, vars->size_x , vars->size_y,  ft_get_rgba(200, 180, 100, 255));
		mlx_image_to_window(vars->mlx, vars->texture2img, vars->save_pos_x, vars->save_pos_y );
		

	}

	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
	{
		vars->size_x -= SPEEX;
		vars->size_y -= SPEEY;
		vars->save_pos_x = vars->texture2img->instances[0].x;
		vars->save_pos_y = vars->texture2img->instances[0].y;
		mlx_delete_image(vars->mlx, vars->texture2img);
		vars->texture2img = mlx_texture_to_image(vars->mlx, vars->texture);
		// ft_create_image(vars, vars->texture2img, vars->size_x , vars->size_y, ft_get_rgba(200, 180, 100, 255));
		mlx_resize_image(vars->texture2img, vars->size_x, vars->size_y);
		mlx_image_to_window(vars->mlx, vars->texture2img, vars->save_pos_x, vars->save_pos_y);

	}

	
}

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
void my_mouse_hook(int button, int x, int y, void* param)
{
	puts("Mouse clicked!");
	
}
// mlx_mousefunc *my_scrollhook(double xdelta, double ydelta, void* param)
// {
// 	// Simple up or down detection.
// 	if (ydelta > 0)
// 		printf("Scrolling up by %f\n", ydelta);
// 	else if (ydelta < 0)
// 		printf("Scrolling up by %f\n", ydelta);
		
	
// 	// Can also detect a mousewheel that goes along the X (e.g: MX Master 3)
// 	if (xdelta < 0)
// 		puts("Sliiiide to the left!");
// 	else if (xdelta > 0)
// 		puts("Sliiiide to the right!");
// }
// void ft_print_texture(t_vars *vars, mlx_image_t *texture)
// {
// 	int i = 0;
// 	int j = 0;
// 	while (i < texture->height)
// 	{
// 		j = 0;
// 		while (j < texture->width)
// 		{
// 			mlx_put_pixel(vars->image, j, i, texture->pixels[i * texture->width + j]);
// 			j++;
// 		}
// 		i++;
// 	}
// }



void ft_put_texture_pix(t_vars *vars, mlx_image_t *img, mlx_texture_t *texture, int x, int y)
{
	int i = 0;
	int j = 0;
	int start_draw_x = x;
	int start_draw_y = y;
	printf("texture->width = %d\n", texture->width);
	printf("texture->height = %d\n", texture->height);
	u_int32_t col = 0;
	int num = 0;
	while(start_draw_x < texture->width)
	{
		start_draw_y = 0;

		while (start_draw_y < texture->height)
		{
			// col = texture->pixels[i + j * texture->width];
			// printf("pixels [%d] = %d\n", num ,texture->pixels[num]);
			mlx_put_pixel(img, start_draw_y, start_draw_x, ft_get_rgba(texture->pixels[num], texture->pixels[num + 1], texture->pixels[num +2],  texture->pixels[num + 3]));
			num+=4;
			start_draw_y++;
		}
		// num+=4;
		start_draw_x++;
		i++;
	}
	// while (i < texture->height)
	// {
	// 	j = 0;
	// 	while (j < texture->width)
	// 	{
	// 		printf("texture pix%d\n", texture->pixels[i + j * texture->width]);
	// 		mlx_put_pixel(img, i, j, texture->pixels[i + j * texture->width]);
	// 		j++;
	// 	}
	// 	start_draw_y++;
	// 	// start_draw_x = x;
	// 	i++;
	// }
}
char **temp_map()
{
	char **map_m;
	map_m = malloc(sizeof(char **) * 11);
	// map_m[0] = malloc(sizeof(char) * 13 +1);
	map_m[0] = "1111111111";
	map_m[1] = "100000001";
	map_m[2] = "10000000001";
	map_m[3] = "1000000001";
	map_m[4] = "10000N0001";
	map_m[5] = "1000000001";
	map_m[6] = "1000000001";
	map_m[7] = "1000000001";
	map_m[8] = "1000000001";
	map_m[9] = "1111111111";
	map_m[10] = NULL;
	// int i = -1;
	// while(map_m[0][++i])
	// 	printf("test%c\n", map_m[0][i]);
	// map->map_matrix[1] = [1,0,0,0,0,0,0,0,0,1];
	// map->map_matrix[2] = [1,0,0,0,0,0,0,0,0,1];
	// map->map_matrix[3] = [1,0,0,0,0,0,0,0,0,1];
	// map->map_matrix[4] = [1,0,0,0,0,0,0,0,0,1];
	// map->map_matrix[5] = [1,0,0,0,0,'N',0,0,0,1];
	// map->map_matrix[6] = [1,0,0,0,0,0,0,0,0,1];
	// map->map_matrix[7] = [1,0,0,0,0,0,0,0,0,1];
	// map->map_matrix[8] = [1,0,0,0,0,0,0,0,0,1];
	// map->map_matrix[9] = [1,1,1,1,1,1,1,1,1,1];
 return (map_m);
}
void ft_read_map(t_vars *vars)
{
	
	int x = -1;
	int y = 0;
	while (vars->map[++x] != NULL)
	{
		y = -1;
		while(vars->map[x][++y])
		{
			if (vars->map[x][y] == 'N')
			{
				printf("asd asd%d    %d", x, y);
				vars->cam[0] = y;
				vars->cam[1] = x;
				return ;
			}
		}
	}
	printf("ERRRROR");

}
int ft_get_fwall(t_vars *vars)
{
	int x;
	int y;
	int dist;

	x = vars->cam[0];
	y = vars->cam[1];
	dist = 0;
	printf("y YYY%d", y);
	while (y != 0)
	{
		printf("csedf %c\n",  vars->map[x][y]);
		if (vars->map[x][y--] == '1')
			break ;
		dist++;
		
	}
	return(dist);
}
void ft_print_other_pix(t_vars *vars)
{
	float sec_line = WIDTH/2;
	float dist;
	float len;
	float media;

	dist = sqrt((sec_line - vars->cam[0] * KOEF )*(sec_line - vars->cam[0] * KOEF));// + (0 - vars->cam[1]  * KOEF)*(0 - vars->cam[1] * KOEF));
	printf("dist2 %f\n", dist);
	len = dist;
	media = (HEIGHT - len) /2;
	int step = 0;
	float sec_step = sec_line;
	while(--sec_line >= 0)
	{
		dist = sqrt((vars->cam[1] * KOEF - sec_step)*(vars->cam[1] * KOEF - sec_step) + (0 - vars->cam[1])*(0 - vars->cam[1]));
		printf("dist %f\n", dist);
		len =  dist;
		media = (HEIGHT - len) /2;
		step = 0;
		while (len > step)
		{
			step++;
			mlx_put_pixel(vars->image, sec_line, media++, 255);
		}
		sec_step+=0.01;
	}
	sec_line = WIDTH/2;
	dist = sqrt((sec_line - vars->cam[0] * KOEF )*(sec_line - vars->cam[0] * KOEF));// + (0 - vars->cam[1]  * KOEF)*(0 - vars->cam[1] * KOEF));
	printf("dist2 %f\n", dist);
	len = HEIGHT - dist;
	media = (HEIGHT - len) /2;
	step = 0;
	sec_step = sec_line;
		while(++sec_line <= WIDTH)
	{
		dist = sqrt((sec_step - vars->cam[1] * KOEF)*(sec_step - vars->cam[1] * KOEF )); //+ (vars->cam[1] - vars->cam[1])*(vars->cam[1] - vars->cam[1]));
		printf("dist %f\n", dist);
		len = HEIGHT - dist;
		media = (HEIGHT - len) /2;
		step = 0;
		while (len > step)
		{
			step++;
			mlx_put_pixel(vars->image, sec_line, media++, 255);
		}
		sec_step+=0.03;
	}
}

void ft_print_fline(t_vars *vars)
{
	int dist;
	float wall[2];
	dist = ft_get_fwall(vars) * KOEF;
	printf("dist%d\n", dist);
	int len = HEIGHT - dist;
	int media = (HEIGHT - len) /2;
	printf("media %d\n", media);
	int step = 0;
	while (len != step)
	{
		step++;
		mlx_put_pixel(vars->image, WIDTH/2, media++, 255);		
	}
	ft_print_other_pix(vars);
}
void ft_touch_wall(t_vars *vars)
{
	int wall[2];

	ft_print_fline(vars);
	// while(vars->map[i][j] != '1')


}
void ft_print_wall(t_vars *vars)
{
	ft_read_map(vars);
	ft_touch_wall(vars);

}

int32_t	main(void)
{
	t_vars *vars;
	vars = malloc(sizeof(t_vars));
	*vars = (t_vars){};
	// map = malloc(sizeof(t_map));
	vars->map = temp_map();
	// printf("%c\n", vars->map[6][6]);
	vars->mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!vars->mlx)
        error();
	vars->sky = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->image = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	ft_create_sky(vars, vars->sky, WIDTH, HEIGHT, ft_get_rgba(100, 210, 250, 250));
	if (mlx_image_to_window(vars->mlx, vars->sky, 0, 0) < 0)
        error();
	ft_print_wall(vars);
	if (mlx_image_to_window(vars->mlx, vars->image, 0, 0) < 0)
		error();
	mlx_loop_hook(vars->mlx, ft_hook, vars);
	mlx_loop(vars->mlx);
	mlx_delete_image(vars->mlx, vars->sky);
	mlx_terminate(vars->mlx);
	
	return (EXIT_SUCCESS);
}