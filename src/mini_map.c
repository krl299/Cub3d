/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:47:24 by mandriic          #+#    #+#             */
/*   Updated: 2023/09/30 11:59:11 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
char **temp_map()
{
	char **map_m;
	int i = 0;
	map_m = malloc(sizeof(char **) * 50);
	map_m[0] = malloc(sizeof(char) * 13 +1);
	// map_m[i++] = "111111111111111111111111111111111111111";
	// map_m[i++] = "111111111111000000111111111111111111111";
	// map_m[i++] = "111111111110000010011111111111111111111";
	// map_m[i++] = "111111111110000111001111111111111111111";
	// map_m[i++] = "111111111110001111100111111111111111111";
	// map_m[i++] = "111111111111011111110011111111111111111";
	// map_m[i++] = "100000000000000000000000000000000000001";
	// map_m[i++] = "10000000000000000N000000000000000000001";
	// map_m[i++] = "10000000000000000111111111111111111111";
	// map_m[i++] = "10111111100111111111111111111111111111";
	// map_m[i++] = "10011111001111111111111111111111111111";
	// map_m[i++] = "11001110011111111111111111111111111111";
	// map_m[i++] = "111001001111111111111111111111111111111";
	// map_m[i++] = "111100011111111111111111111111111111111";
	// map_m[i++] = "111111111111111111111111111111111111111";
	// map_m[i++] = "111111111111111111111111111111111111111";
	// map_m[i++] = "111111111111111111111111111111111111111";
	// map_m[i++] = "111111111111111111111111111111111111111";
	// map_m[i++] = "111111111111111111111111111111111111111";
	// map_m[i++] = "111111111111111111111111111111111111111";
	// map_m[i++] = "111111111111111111111111111111111111111";
	// map_m[i++] = "111111111111111111111111111111111111111";
	// 	map_m[i] = NULL;
	map_m[i++] = "111111111111111111111111";
	map_m[i++] = "100000000000000000000001";
	map_m[i++] = "100000000000000000000001";
	map_m[i++] = "100000000000000000000001";
	map_m[i++] = "100000000000000000000001";
	map_m[i++] = "100101001000100010001001";
	map_m[i++] = "100000000000000000000001";
	map_m[i++] = "100000000000000000000001";
	map_m[i++] = "100000000000000000000001";
	map_m[i++] = "100000000000000000000001";
	map_m[i++] = "100000000000000000000001";
	map_m[i++] = "100000000000000000000001";
	map_m[i++] = "100000000000000000000001";
	map_m[i++] = "100000000000000000000001";
	map_m[i++] = "100000000000000000000001";
	map_m[i++] = "1000000000000000000000N1";
	map_m[i++] = "111111111111111111111111";
		map_m[i] = NULL;

	// map_m[i++] = "10000000000000000111111111111111111111";
	// map_m[i++] = "10000000000000000000000000000000000001";
	// map_m[i++] = "10000000000000000000000000000000000001";
	// map_m[i++] = "10000000000000000000000000000000000001";
	// map_m[i++] = "10000000000000000111111111111111111111";
	// map_m[i++] = "10000000N000000001";
	// map_m[i++] = "100000000000000001";
	// map_m[i++] = "100011111100000001";
	// map_m[i++] = "100000000111111111";
	// map_m[i++] = "10001001111";
	// map_m[i++] = "10010000001";
	// map_m[i++] = "10000000001";
	// map_m[i++] = "1000000001";
	// map_m[i++] = "10000000001";
	// map_m[i++] = "10000000001";
	// map_m[i++] = "10000000001";
	// map_m[i++] = "10000000001";
	// map_m[i++] = "10000000001";
	// map_m[i++] = "10000000001";
	// map_m[i++] = "10000000001";
	// map_m[i++] = "11111111111";
	// map_m[i] = NULL;
// map_m[i++] = "000000001111111111111111111111111";
// map_m[i++] = "000000001000000000110000000000001";
// map_m[i++] = "000000001011000001110000000000001";
// map_m[i++] = "000000001001000000000000000000001";
// map_m[i++] = "111111111011000001110000000000001";
// map_m[i++] = "100000000011000001110111111111111";
// map_m[i++] = "111101111111110111000000100010000";
// map_m[i++] = "111101111111110111010100100010000";
// map_m[i++] = "110000001101010111000000100010000";
// map_m[i++] = "100000000000000111000000100010000";
// map_m[i++] = "100000N0000001111010100000010000";
// map_m[i++] = "110000011101010111110111100011100";
// map_m[i++] = "111101110111010101011110100010000";
// map_m[i++] = "111111110111111101111111111110000";
// map_m[i] = NULL;

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
	while (vars->map_vars->map[++x] != NULL)
	{
		y = -1;
		while(vars->map_vars->map[x][++y])
		{
			if (vars->map_vars->map[x][y] == 'N')
			{
				printf("asd asd%d    %d", x, y);
				vars->map_vars->cam[0] = y;
				vars->map_vars->cam[1] = x;
				return ;
			}
		}
	}
	printf("ERRRROR");
}

void ft_print_wall(int wall, int x, int y, t_vars *vars)
{
	int one = WIDTH/4/vars->map_vars->len_mm[1];
	vars->map_vars->len_char = one;
	// printf("one = %d", one);
	if (wall == 0)
	{
		int i = -1;
		while(++i < one)
		{
			int j = -1;
			while(++j < one)
			{
				mlx_put_pixel(vars->mini_map, y * one + j, x * one + i, 0x00000000);
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
				mlx_put_pixel(vars->mini_map, y * one + j, x * one + i, ft_get_rgba(255, 255, 0, 255));
			}
		}
	}
}

void ft_mini_unit(int x, int y, t_vars *vars)
{
	if (vars->mini_unit == NULL)
		vars->mini_unit = mlx_new_image(vars->mlx, vars->map_vars->len_char * vars->map_vars->len_mm[0], vars->map_vars->len_char * vars->map_vars->len_mm[0]);
	vars->map_vars->cont_y = y * vars->map_vars->len_char;
	vars->map_vars->cont_x = x * vars->map_vars->len_char;
	int i = -1;
	int save_y = y;
	int j = -1;
	while(++i <  vars->map_vars->len_char )
	{
		int j = -1;
		while(++j <  vars->map_vars->len_char)
        {
            if (vars->map_vars->len_char/2 >= sqrt(pow(i -  vars->map_vars->len_char/2, 2) + pow(j -  vars->map_vars->len_char/2, 2)))
    			mlx_put_pixel(vars->mini_unit, x *  vars->map_vars->len_char  + j, x *  vars->map_vars->len_char  + i, ft_get_rgba(200, 88, 60, 255));
        }
	}
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
	ft_trace_line(vars);
}

