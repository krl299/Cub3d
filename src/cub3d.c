/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:37:50 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/10/12 14:06:34 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
c == '\f' || c == 'r' || c == ' ')
		return (1);
	else
		return (0);
}

void	ft_leaks(void)
{
	system("leaks -q cub3d");
}

void	ft_draw_line(t_vars * vars, int x_u, int y_u, float x_w, float y_w, int x, float mem_angle)
{
	float dist;
	float line_len;
	float lenght_with_koef;

	int y = 1;
	int y_mem = 1;
	static int clean[WIDTH * HEIGHT * 2][2];
	static int i_cl = 0;
	if (vars->map_vars->clean_walls == 1)
	{
		int j = -1;
		while(++j <= i_cl)
		{
			mlx_put_pixel(vars->wall, clean[j][0], clean[j][1], ft_get_rgba(0, 0, 0, 0));
		}
		vars->map_vars->clean_walls = 0;
		i_cl = 0;
	}
	dist = sqrt(pow(x_w - x_u, 2) + pow(y_w - y_u, 2));
	lenght_with_koef = HEIGHT - (dist * 2 * cos(vars->map_vars->mini_u_angle - mem_angle)) ;
	// lenght_with_koef += 1;
	int q,w,e = 0;
		int i = -1;
		while(++i < (int)lenght_with_koef-1)
		{
			if (y % 2 == 0)
				y = HEIGHT/2 + i/2;
			else
				y = HEIGHT/2 - i/2;
				
			if (y < HEIGHT  && y > 0)
			{
				mlx_put_pixel(vars->wall, x, y, ft_get_rgba(0, 0, 0, 255));
				clean[i_cl][0] = x;
				clean[i_cl++][1] = y;
			}
		}
}

void ft_trace_line(t_vars *vars)
{
		float fx;
		float fy;
		float mem_x;
		float mem_y;
		static int clean[WIDTH * HEIGHT][2];
		static int mem_clean = 0;
		static int i = 0;
		static float angle_step = 0.1;

		mem_x = vars->map_vars->cont_x + vars->map_vars->len_char;
		mem_y = vars->map_vars->cont_y + 1;
		if (mem_clean != 0)
		{
			int j = -1;
			while(++j <= mem_clean)
			{
				mlx_put_pixel(vars->mini_map, clean[j][0], clean[j][1], ft_get_rgba(0, 0, 0, 0));
			}
			mem_clean = 0;
		}
		float mem_angle = vars->map_vars->mini_u_angle;
		int i2 = WIDTH/2;
		while(i2-- > 0)
		{
			i = 0;
			while (i++ != WIDTH/4)
			{
				mem_x = cos(vars->map_vars->mini_u_angle) + mem_x;
				mem_y = sin(vars->map_vars->mini_u_angle) + mem_y;
				if(vars->map_vars->map[(int)(mem_x - vars->map_vars->len_char/2)/ (vars->map_vars->len_char)][((int)mem_y+ vars->map_vars->len_char/2)/ vars->map_vars->len_char] != '1' &&\
					vars->map_vars->map[(int)(mem_x - vars->map_vars->len_char /2) / vars->map_vars->len_char][((int)mem_y + vars->map_vars->len_char /2) / vars->map_vars->len_char] != '1')
					{
						mlx_put_pixel(vars->mini_map, mem_y + (vars->map_vars->len_char/2), mem_x - (vars->map_vars->len_char/2), ft_get_rgba(255, 255, 255, 255));
						clean[mem_clean][0] = mem_y + (vars->map_vars->len_char/2);
						clean[mem_clean++][1] = mem_x - (vars->map_vars->len_char/2);
					}
					else
						break;
			}
			ft_draw_line(vars,vars->map_vars->cont_x + vars->map_vars->len_char, vars->map_vars->cont_y - 1, mem_x, mem_y, i2, mem_angle);
			mem_x = vars->map_vars->cont_x + vars->map_vars->len_char;
			mem_y = vars->map_vars->cont_y + 1;
			vars->map_vars->mini_u_angle+= 0.0003;
			// printf("angle: %f\n", (M_PI * 2 / 32) * 32); // angle / 1 sector
		}
		vars->map_vars->mini_u_angle = mem_angle;
		// float center = vars->map_vars->mini_u_angle;
		i2 = WIDTH/2-1;
		while(i2++ < WIDTH)
		{
			i = 0;
			while (i++ != WIDTH/4)
			{
				mem_x = cos(vars->map_vars->mini_u_angle) + mem_x;
				mem_y = sin(vars->map_vars->mini_u_angle) + mem_y;
				if(vars->map_vars->map[(int)(mem_x - vars->map_vars->len_char/2)/ (vars->map_vars->len_char)][((int)mem_y+ vars->map_vars->len_char/2)/ vars->map_vars->len_char] != '1' &&\
					vars->map_vars->map[(int)(mem_x - vars->map_vars->len_char /2) / vars->map_vars->len_char][((int)mem_y + vars->map_vars->len_char /2) / vars->map_vars->len_char] != '1')
					{
						mlx_put_pixel(vars->mini_map, mem_y + (vars->map_vars->len_char/2), mem_x - (vars->map_vars->len_char/2), ft_get_rgba(255, 255, 255, 255));
						clean[mem_clean][0] = mem_y + (vars->map_vars->len_char/2);
						clean[mem_clean++][1] = mem_x - (vars->map_vars->len_char/2);
					}
					else
						break;
			}
			ft_draw_line(vars,vars->map_vars->cont_x + vars->map_vars->len_char, vars->map_vars->cont_y - 1, mem_x, mem_y, i2, mem_angle);
			mem_x = vars->map_vars->cont_x + vars->map_vars->len_char;
			mem_y = vars->map_vars->cont_y + 1;
			vars->map_vars->mini_u_angle-= 0.0003;
			// printf("angle: %f\n", (M_PI * 2 / 32) * 32); // angle / 1 sector
		}
		static float one_grad = (M_PI * 2)/ 360;
		static float sect_grad = 360 / 32;
		static float sector = ((M_PI * 2) / 32);
		vars->map_vars->go_angle = (mem_angle / sector);
		// float one_sect_step
		// if (sector_now > 32)
		// 	sector_now = 0;
		// if (sector_now < 0)
		// 	sector_now = 32;
		printf("angle: %f sect now: %f\n", mem_angle, vars->map_vars->go_angle); // angle / 1 sector
		// printf("angle: %f %f %f\n", one_grad, sect_grad, sector); // angle / 1 sector

		vars->map_vars->clean_walls = 1;
		vars->map_vars->mini_u_angle = mem_angle;
}

// int32_t	submain(t_file_info *info)
int32_t	submain()
{
	t_vars *vars; // Todas variables
	vars = malloc(sizeof(t_vars));
	*vars = (t_vars){};
	vars->map_vars = malloc(sizeof(t_map));
	*vars->map_vars = (t_map){};
	vars->map_vars->mini_u_angle = M_PI/2;//1.5708;

	vars->map_vars->map = temp_map(); //aqui se cambia luego a mapa de parser
	vars->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	// if (!vars->mlx)
    //     error();
	vars->sky = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->mini_map = mlx_new_image(vars->mlx, WIDTH/4, WIDTH/4);
	vars->wall = mlx_new_image(vars->mlx, WIDTH, HEIGHT *2);
	ft_create_sky(vars, vars->sky, WIDTH, HEIGHT, ft_get_rgba(100, 210, 250, 250));
	ft_create_mmap(vars);
	vars->map_vars->start_draw_y_mm = HEIGHT - (WIDTH/4/vars->map_vars->len_mm[1]) * vars->map_vars->len_mm[0];
	mlx_image_to_window(vars->mlx, vars->sky, 0, 0);
	// mlx_image_to_window(vars->mlx, vars->mini_map, 0, vars->map_vars->start_draw_y_mm);
	mlx_image_to_window(vars->mlx, vars->mini_unit, 0, vars->map_vars->start_draw_y_mm);
	mlx_image_to_window(vars->mlx, vars->wall, 0, 0);
	mlx_image_to_window(vars->mlx, vars->mini_map, 0, vars->map_vars->start_draw_y_mm);
	mlx_loop_hook(vars->mlx, ft_hook, vars);
	mlx_loop(vars->mlx);
	mlx_delete_image(vars->mlx, vars->sky);
	mlx_terminate(vars->mlx);
	
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_file_info	info;

//	atexit(ft_leaks);
	if (argc == 2)
	{
		// ft_init_info(&info);
		// ft_check_arg(argv[1], &info);
		// ft_clean_info(&info);
		// submain(&info);
		submain();
	}
	else
		ft_error_msg(1, &info);
	return (0);
}