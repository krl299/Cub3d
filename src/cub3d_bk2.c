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



char **temp_map()
{
	char **map_m;
	map_m = malloc(sizeof(char **) * 50);
	// map_m[0] = malloc(sizeof(char) * 13 +1);
	map_m[0] = "111111111111111111";
	map_m[1] = "100000000000000001";
	map_m[2] = "100000000000000001";
	map_m[3] = "100000000000000001";
	map_m[4] = "10000N000000000001";
	map_m[5] = "101111111100000001";
	map_m[6] = "100000000111111111";
	map_m[7] = "1001001111";
	map_m[8] = "1001000001";
	map_m[9] = "1000000001";
	map_m[10] = "1000000001";
	map_m[11] = "1000000001";
	map_m[12] = "1000000001";
	map_m[13] = "1111111111";
	map_m[14] = NULL;

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
void ft_print_wall(int wall, int x, int y, t_vars *vars)
{
	int one = WIDTH/4/vars->len_mm[1];
	vars->len_char = one;
	printf("one = %d", one);
	if (wall == 0)
	{
		int i = -1;
		while(++i < one)
		{
			int j = -1;
			while(++j < one)
			{
				mlx_put_pixel(vars->mini_map, y * one + j, x * one + i, 0x00FF00FF);
			}
		}
	}
	else if (wall == 1)
	{
		int i = -1;
		while(++i < one)
		{
			int j = -1;
			while(++j < one)
			{
				mlx_put_pixel(vars->mini_map, y * one + j, x * one + i, ft_get_rgba(255, 255, 0, 101));
			}
		}
	}
	else if (wall == 2)
	{
		if (vars->mini_unit == NULL)
			vars->mini_unit = mlx_new_image(vars->mlx, vars->len_char * vars->len_mm[0], vars->len_char * vars->len_mm[1]);
		int i = -1;
		int unit_x = 0;
		int unit_y = 0;
		vars->put_unit_y = x * one + (HEIGHT - (WIDTH/4/vars->len_mm[1]) * vars->len_mm[0]);
		vars->put_unit_x = y * one;
		while(++i < one)
		{
			int j = -1;
			unit_y = 0;
			while(++j < one)
			{
				if (one/2 <= 5 + sqrt(pow(i - one/2, 2) + pow(j - one/2, 2)))
				{
					mlx_put_pixel(vars->mini_map, y * one + j, x * one + i, 0x00FF00FF);	
					mlx_put_pixel(vars->mini_unit, unit_x, unit_y++, 0x00FF00FF);

				}
				else
				{
					mlx_put_pixel(vars->mini_map, y * one + j, x * one + i, 0x00FF00FF);
					mlx_put_pixel(vars->mini_unit, unit_x, unit_y++,  0xFF5555FF);

				}
				// mlx_put_pixel(vars->mini_map, y * one + j, x * one + i, 0xFFFFFFFF);
			}
			unit_x++;
		}
	}
}
void ft_maxlen_mm(t_vars *vars)
{
	int x = -1;
	while(vars->map[++x] != NULL)
	{
		int y = -1;
		while(vars->map[x][++y])
		{

	
		}
		if (vars->len_mm[1] < y)
			vars->len_mm[1] = y;
	}
	vars->len_mm[0] = x;
}
void ft_trace_line(t_vars *vars)
{
	int x = 0;
	int y = 0;
	float fx;
	float fy;
	float angle = M_PI/2 *3;//1.5708;
	float angle_step = 0.1;
	int i = -1;
	mlx_put_pixel(vars->mini_unit, vars->mini_unit_xy[0] * vars->len_char, vars->mini_unit_xy[1] * vars->len_char, ft_get_rgba(255, 255, 255, 255));
	while(angle_step < 200)
	{
		fx = x + angle_step * cos(angle);
		fy = y + angle_step * sin(angle);

		mlx_put_pixel(vars->mini_unit, (int)fy, (int)fx, ft_get_rgba(255, 255, 255, 255));
		angle_step += 0.01;
		printf("(int)fy/vars->len_char = %d, (int)fx/vars->len_char = %d\n", (int)fy/vars->len_char, (int)fx/vars->len_char);
		printf("vars->map[(int)fy/vars->len_char][(int)fx/vars->len_char] = %c\n", vars->map[(int)fy/vars->len_char][(int)fx/vars->len_char]);
		// if (vars->map[(int)fy/vars->len_char][(int)fx/vars->len_char] == '1')
		// 	break;
	}
	// mlx_put_pixel(vars->mini_map, vars->mini_unit_xy[1] * vars->len_char + vars->len_char/2, vars->mini_unit_xy[0] * vars->len_char + vars->len_char/2, ft_get_rgba(255, 255, 255, 255));
	// printf("vars->mini_unit_xy[1] = %d, vars->mini_unit_xy[0] = %d\n", vars->mini_unit_xy[1]* vars->len_char, vars->mini_unit_xy[0]* vars->len_char);

}
void ft_create_mmap(t_vars *vars)
{
	int x= -1;
	ft_maxlen_mm(vars);
	while (vars->map[++x] != NULL)
	{
		int y = -1;
		while (vars->map[x][++y])
		{
			if (vars->map[x][y] == '0')
			{

				ft_print_wall(0, x, y, vars);
			}
			else if (vars->map[x][y] == '1')
			{
				ft_print_wall(1, x, y, vars);
			}
			else if (vars->map[x][y] == 'N')
			{
				vars->mini_unit_xy[0] = x;
				vars->mini_unit_xy[1] = y;
				ft_print_wall(2, x, y, vars);
			}
		}	
	}
	ft_trace_line(vars);
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
	// if (!vars->mlx)
    //     error();
	vars->sky = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->mini_map = mlx_new_image(vars->mlx, WIDTH/4, WIDTH/4);
	ft_create_sky(vars, vars->sky, WIDTH, HEIGHT, ft_get_rgba(100, 210, 250, 250));
	ft_create_mmap(vars);
	mlx_image_to_window(vars->mlx, vars->sky, 0, 0);
	mlx_image_to_window(vars->mlx, vars->mini_map, 0, HEIGHT - (WIDTH/4/vars->len_mm[1]) * vars->len_mm[0]);
	mlx_image_to_window(vars->mlx, vars->mini_unit, vars->put_unit_x, vars->put_unit_y);
	printf("put_unit_x = %d, put_unit_y = %d\n", vars->put_unit_x, vars->put_unit_y);
        // error();	
	mlx_loop_hook(vars->mlx, ft_hook, vars);
	mlx_loop(vars->mlx);
	mlx_delete_image(vars->mlx, vars->sky);
	mlx_terminate(vars->mlx);
	
	return (EXIT_SUCCESS);
}