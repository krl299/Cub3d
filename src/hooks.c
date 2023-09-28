#include "../includes/cub3d.h"

void debug(t_vars *vars)
{
	// write(1,"vars->map_vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] + 1] = ", 62);
	// write(1, &vars->map_vars->map[(vars->map_vars->cont_x) / vars->map_vars->len_char][vars->map_vars->cont_y / vars->map_vars->len_char], 1);
	// write(1, "\n", 1);
	// write(1, "cont_x_left=", 13);
	// write(1, ft_itoa(vars->map_vars->cont_x), ft_strlen(ft_itoa(vars->map_vars->cont_x)));
	// write(1, "\n", 1);
	// write(1, "vars->map_vars->cont_x / vars->map_vars->len_char=", 36);
	// write(1, ft_itoa(vars->map_vars->cont_x / vars->map_vars->len_char), ft_strlen(ft_itoa(vars->map_vars->cont_x / vars->map_vars->len_char)));
	// write(1, "\n", 1);
	// write(1, "vars->map_vars->cont_y / vars->map_vars->len_char=", 33);
	// write(1, ft_itoa(vars->map_vars->cont_y / vars->map_vars->len_char), ft_strlen(ft_itoa(vars->map_vars->cont_y / vars->map_vars->len_char)));

	// // write(1, ft_itoa(vars->mini_unit_xy[0]), ft_strlen(ft_itoa(vars->mini_unit_xy[0])));
	// // write(1, ",x= ", 4);
	// // write(1, ft_itoa(vars->mini_unit_xy[1]), ft_strlen(ft_itoa(vars->mini_unit_xy[1])));
	// write(1, "\n", 1);
}

void ft_hook(void* param)
{
	t_vars *vars;
	vars = param;

	// printf("vars->mini_unit_xy[0]%d, vars->mini_unit_xy[1]%d\n", vars->mini_unit_xy[0], vars->mini_unit_xy[1]);
	// printf("vars->map_vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] + 1]==== %c\n", vars->map_vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] + 1]);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);

	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
	{																					//+ 1
		if(vars->map_vars->map[(vars->map_vars->cont_x)/ vars->map_vars->len_char][(vars->map_vars->cont_y) / vars->map_vars->len_char + 1] != '1' &&\
			vars->map_vars->map[(vars->map_vars->cont_x + vars->map_vars->len_char - 1)/ vars->map_vars->len_char][(vars->map_vars->cont_y + vars->map_vars->len_char) / vars->map_vars->len_char] != '1')
		{
			vars->map_vars->cont_y++;
			vars->mini_unit->instances[0].x += SPEEX;
		}
		ft_trace_line(vars);

		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->map_vars->len_char);
		debug(vars);
	}

	// 	// 	vars->mini_unit->instances[0].x += SPEEX;
	// 	// }
	// 	// debug(vars);
	// }
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
	// 	// vars->gun->instances[0].x-= 3;
	{

		if(vars->map_vars->map[(vars->map_vars->cont_x) / vars->map_vars->len_char][(vars->map_vars->cont_y  - 1) / vars->map_vars->len_char] != '1' &&\
			vars->map_vars->map[(vars->map_vars->cont_x + vars->map_vars->len_char - 1) / vars->map_vars->len_char][(vars->map_vars->cont_y - 1)/ vars->map_vars->len_char] != '1')
		{
			vars->map_vars->cont_y--;

			vars->mini_unit->instances[0].x -= SPEEX;
		}
		ft_trace_line(vars);

		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->map_vars->len_char);
		debug(vars);
	}
		// else if (vars->map_vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] - 1] == '1' && vars->map_vars->cont_x != 1)
		// {
		// 	if (vars->map_vars->cont_x-- == 1)
		// 	{
		// 			vars->mini_unit_xy[1] -= 1;
		// 			vars->map_vars->cont_x = vars->map_vars->len_char;
				
		// 	}
		// 	vars->mini_unit->instances[0].x -= SPEEX;
		// }
		// debug(vars);

	// }
	
	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
	{	
		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->map_vars->len_char);
		if(vars->map_vars->map[(vars->map_vars->cont_x - 1)/ vars->map_vars->len_char][(vars->map_vars->cont_y)/ vars->map_vars->len_char] != '1' &&\
			vars->map_vars->map[(vars->map_vars->cont_x - 1) / vars->map_vars->len_char][(vars->map_vars->cont_y + vars->map_vars->len_char - 1) / vars->map_vars->len_char] != '1')
		{
			vars->map_vars->cont_x--;

			vars->mini_unit->instances[0].y -= SPEEX;
		}
		debug(vars);
		ft_trace_line(vars);

	}

	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
	{
		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->map_vars->len_char);
		if(vars->map_vars->map[(vars->map_vars->cont_x + vars->map_vars->len_char) / vars->map_vars->len_char][(vars->map_vars->cont_y + vars->map_vars->len_char - 1) / vars->map_vars->len_char] != '1' &&\
			vars->map_vars->map[(vars->map_vars->cont_x+ vars->map_vars->len_char)/ vars->map_vars->len_char][vars->map_vars->cont_y  / vars->map_vars->len_char] != '1')
		{
			vars->map_vars->cont_x++;
			vars->mini_unit->instances[0].y += SPEEX;
		}
		ft_trace_line(vars);

		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->map_vars->len_char);
		debug(vars);


	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
	{
		vars->map_vars->mini_u_angle -= 0.02;
		ft_trace_line(vars);

	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
	{
		vars->map_vars->mini_u_angle += 0.02;
		ft_trace_line(vars);

	}
}