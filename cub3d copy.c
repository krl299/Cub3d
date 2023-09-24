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
	map_m[0] = malloc(sizeof(char) * 13 +1);
	map_m[0] = "111111";
	map_m[1] = "100000111111111111";
	map_m[2] = "100000000000000001";
	map_m[3] = "10000000N000000001";
	map_m[4] = "100000000000000001";
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

	// map_m[0] = "1111111";
	// map_m[1] = "1N00001";
	// map_m[2] = "1001001";
	// map_m[3] = "1000001";
	// map_m[4] = "1000001";
	// map_m[5] = "1111111";
	// map_m[6] = NULL;
 return (map_m);
}
void ft_read_map(t_vars *vars)
{
	
	int x = -1;
	int y = 0;
	while (vars->map_vars->map_vars->map_vars->map[++x] != NULL)
	{
		y = -1;
		while(vars->map_vars->map_vars->map_vars->map[x][++y])
		{
			if (vars->map_vars->map_vars->map_vars->map[x][y] == 'N')
			{
				printf("asd asd%d    %d", x, y);
				vars->map_vars->map_vars->map_vars->cam[0] = y;
				vars->map_vars->map_vars->map_vars->cam[1] = x;
				return ;
			}
		}
	}
	printf("ERRRROR");

}
void ft_print_wall(int wall, int x, int y, t_vars *vars)
{
	int one = WIDTH/4/vars->map_vars->map_vars->map_vars->len_mm[1];
	vars->map_vars->len_char = one;
	printf("one = %d", one);
	if (wall == 0)
	{
		int i = -1;
		while(++i < one)
		{
			int j = -1;
			while(++j < one)
			{
				mlx_put_pixel(vars->map_vars->mini_map, y * one + j, x * one + i, 0x00000000);
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
				mlx_put_pixel(vars->map_vars->mini_map, y * one + j, x * one + i, ft_get_rgba(255, 255, 0, 101));
			}
		}
	}
}

void ft_mini_unit(int x, int y, t_vars *vars)
{
	if (vars->map_vars->mini_unit == NULL)
		vars->map_vars->mini_unit = mlx_new_image(vars->map_vars->mlx, vars->map_vars->len_char * vars->map_vars->len_mm[0], vars->map_vars->len_char * vars->map_vars->len_mm[0]);
	vars->map_vars->mini_unit_xy[0] = x;
	vars->map_vars->mini_unit_xy[1] = y;
	vars->map_vars->cont_y_down = 1;
	vars->map_vars->cont_y_up = y * vars->map_vars->len_char;
	vars->map_vars->cont_x_left = x * vars->map_vars->len_char;
	vars->map_vars->cont_x_right = 1;
	printf("vars->map_vars->mini_unit_xy[0]%d, vars->map_vars->mini_unit_xy[1]%d\n", vars->map_vars->mini_unit_xy[0], vars->map_vars->mini_unit_xy[1]);
	int i = -1;
	int save_y = y;
	int j = -1;
	while(++i <  vars->map_vars->len_char )
	{
		int j = -1;
		while(++j <  vars->map_vars->len_char )
		{
			if (vars->map_vars->len_char/2 <= 5 + sqrt(pow(i -  vars->map_vars->len_char/2, 2) + pow(j -  vars->map_vars->len_char/2, 2)))
			{
				// mlx_put_pixel(vars->map_vars->mini_map, y * vars->map_vars->len_char + j, x * vars->map_vars->len_char + i, 0x00FF00FF);
				// mlx_put_pixel(vars->map_vars->mini_unit, y * vars->map_vars->len_char + j, x * vars->map_vars->len_char + i, 0x00FF00FF);
				// mlx_put_pixel(vars->map_vars->mini_unit, y *  vars->map_vars->len_char  + j, x *  vars->map_vars->len_char  + i, 0x00FF00FF);	
			}
			else
			{
				// mlx_put_pixel(vars->map_vars->mini_map, y * vars->map_vars->len_char + j, x * vars->map_vars->len_char + i, 0x00FF00FF);
				mlx_put_pixel(vars->map_vars->mini_unit, y *  vars->map_vars->len_char  + j, x *  vars->map_vars->len_char  + i, ft_get_rgba(200, 88, 60, 255));

			}
			// mlx_put_pixel(vars->map_vars->mini_map, y *  vars->map_vars->len_char  + j, x *  vars->map_vars->len_char  + i, 0xFFFFFFFF);
		}
	}
		// while(++j <  vars->map_vars->len_char)
		// {
		// 	if (vars->map_vars->len_char/2 <= 5 + sqrt(pow(i -  vars->map_vars->len_char/2, 2) + pow(j -  vars->map_vars->len_char/2, 2)))
		// 	{
		// 		mlx_put_pixel(vars->map_vars->mini_map, x, y + i, 0x00FF00FF);	
		// 		mlx_put_pixel(vars->map_vars->mini_unit, x, y * vars->map_vars->len_char + i, 0x00FF00FF);

		// 	}
		// 	else
		// 	{
		// 		// mlx_put_pixel(vars->map_vars->mini_map, y * vars->map_vars->len_char + j, x * vars->map_vars->len_char + i, 0x00FF00FF);
		// 		// mlx_put_pixel(vars->map_vars->mini_unit,  y * vars->map_vars->len_char + j, x * vars->map_vars->len_char + i,  0xFF5555FF);

		// 	}
		// 	// mlx_put_pixel(vars->map_vars->mini_map, y * one + j, x * one + i, 0xFFFFFFFF);
		// }
		// x++;
	// }
}

void ft_maxlen_mm(t_vars *vars)
{
	int x = -1;
	while(vars->map_vars->map[++x] != NULL)
	{
		int y = -1;
		while(vars->map_vars->map[x][++y])
			;
		if (vars->map_vars->len_mm[1] < y)
			vars->map_vars->len_mm[1] = y;
	}
	vars->map_vars->len_mm[0] = x;
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
		int mem_x;
		int mem_y;

	mem_x = vars->map_vars->mini_unit_xy[0];
	mem_y = vars->map_vars->mini_unit_xy[1];
	while (1)
	{
	if(vars->map_vars->map[(mem_x)/ vars->map_vars->len_char][(vars->map_vars->cont_y_up)/ vars->map_vars->len_char] != '1' &&\
		vars->map_vars->map[(mem_x) / vars->map_vars->len_char][(vars->map_vars->cont_y_up + vars->map_vars->len_char - 1) / vars->map_vars->len_char] != '1')
		{
			mlx_put_pixel(vars->map_vars->map_varsmini_map, mem_y + (vars->map_vars->len_char/2), mem_x - (vars->map_vars->len_char/2), ft_get_rgba(255, 255, 255, 255));
			mem_x--;
			printf("cjeckleft\n");
		}
		else
			break;
	}

	// mlx_put_pixel(vars->map_vars->mini_unit, vars->map_vars->mini_unit_xy[0] * vars->map_vars->len_char, vars->map_vars->mini_unit_xy[1] * vars->map_vars->len_char, ft_get_rgba(255, 255, 255, 255));
	// while(angle_step < 200)
	// {
	// 	fx = x + angle_step * cos(angle);
	// 	fy = y + angle_step * sin(angle);

	// 	mlx_put_pixel(vars->map_vars->mini_unit, (int)fy, (int)fx, ft_get_rgba(255, 255, 255, 255));
	// 	angle_step += 0.01;
	// 	printf("(int)fy/vars->map_vars->len_char = %d, (int)fx/vars->map_vars->len_char = %d\n", (int)fy/vars->map_vars->len_char, (int)fx/vars->map_vars->len_char);
	// 	printf("vars->map_vars->map[(int)fy/vars->map_vars->len_char][(int)fx/vars->map_vars->len_char] = %c\n", vars->map_vars->map[(int)fy/vars->map_vars->len_char][(int)fx/vars->map_vars->len_char]);
	// 	// if (vars->map_vars->map[(int)fy/vars->map_vars->len_char][(int)fx/vars->map_vars->len_char] == '1')
	// 	// 	break;
	// }
	// mlx_put_pixel(vars->map_vars->mini_map, vars->map_vars->mini_unit_xy[1] * vars->map_vars->len_char + vars->map_vars->len_char/2, vars->map_vars->mini_unit_xy[0] * vars->map_vars->len_char + vars->map_vars->len_char/2, ft_get_rgba(255, 255, 255, 255));
	// printf("vars->map_vars->mini_unit_xy[1] = %d, vars->map_vars->mini_unit_xy[0] = %d\n", vars->map_vars->mini_unit_xy[1]* vars->map_vars->len_char, vars->map_vars->mini_unit_xy[0]* vars->map_vars->len_char);

}
void ft_create_mmap(t_vars *vars)
{
	int x= -1;
	ft_maxlen_mm(vars);
	while (vars->map_vars->map[++x] != NULL)
	{
		int y = -1;
		while (vars->map_vars->map[x][++y])
		{
			if (vars->map_vars->map[x][y] == '0')
			{

				ft_print_wall(0, x, y, vars);
			}
			else if (vars->map_vars->map[x][y] == '1')
			{
				ft_print_wall(1, x, y, vars);
			}
			else if (vars->map_vars->map[x][y] == 'N')
			{
				vars->map_vars->mini_unit_xy[0] = x;
				vars->map_vars->mini_unit_xy[1] = y;
				ft_mini_unit(x, y, vars);
			}
		}	
	}
	// ft_trace_line(vars);
}
int32_t	main(void)
{
	t_vars *vars;
	vars = malloc(sizeof(t_vars));
	*vars = (t_vars){};
	// map = malloc(sizeof(t_map));
	vars->map_vars->map = temp_map();
	// printf("%c\n", vars->map_vars->map[6][6]);
	vars->map_vars->mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	// if (!vars->map_vars->mlx)
    //     error();
	vars->map_vars->sky = mlx_new_image(vars->map_vars->mlx, WIDTH, HEIGHT);
	vars->map_vars->mini_map = mlx_new_image(vars->map_vars->mlx, WIDTH/4, WIDTH/4);
	ft_create_sky(vars, vars->map_vars->sky, WIDTH, HEIGHT, ft_get_rgba(100, 210, 250, 250));
	ft_create_mmap(vars);
	vars->map_vars->start_draw_y_mm = HEIGHT - (WIDTH/4/vars->map_vars->len_mm[1]) * vars->map_vars->len_mm[0];
	mlx_image_to_window(vars->map_vars->mlx, vars->map_vars->sky, 0, 0);
	mlx_image_to_window(vars->map_vars->mlx, vars->map_vars->mini_map, 0, vars->map_vars->start_draw_y_mm);
	mlx_image_to_window(vars->map_vars->mlx, vars->map_vars->mini_unit, 0, vars->map_vars->start_draw_y_mm);
	printf("put_unit_x = %d, put_unit_y = %d\n", vars->map_vars->put_unit_x, vars->map_vars->put_unit_y);
        // error();	
	
	mlx_loop_hook(vars->map_vars->mlx, ft_hook, vars);
	mlx_loop(vars->map_vars->mlx);
	mlx_delete_image(vars->map_vars->mlx, vars->map_vars->sky);
	mlx_terminate(vars->map_vars->mlx);
	
	return (EXIT_SUCCESS);
}