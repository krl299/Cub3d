#include "../includes/cub3d.h"

void debug(t_vars *vars)
{
	write(1,"vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] + 1] = ", 62);
	write(1, &vars->map[(vars->cont_x_left) / vars->len_char][vars->cont_y_up / vars->len_char], 1);
	write(1, "\n", 1);
	write(1, "cont_x_left=", 13);
	write(1, ft_itoa(vars->cont_x_left), ft_strlen(ft_itoa(vars->cont_x_left)));
	write(1, "\n", 1);
	write(1, "vars->cont_x_left / vars->len_char=", 36);
	write(1, ft_itoa(vars->cont_x_left / vars->len_char), ft_strlen(ft_itoa(vars->cont_x_left / vars->len_char)));
	write(1, "\n", 1);
	write(1, "vars->cont_y_up / vars->len_char=", 33);
	write(1, ft_itoa(vars->cont_y_up / vars->len_char), ft_strlen(ft_itoa(vars->cont_y_up / vars->len_char)));

	// write(1, ft_itoa(vars->mini_unit_xy[0]), ft_strlen(ft_itoa(vars->mini_unit_xy[0])));
	// write(1, ",x= ", 4);
	// write(1, ft_itoa(vars->mini_unit_xy[1]), ft_strlen(ft_itoa(vars->mini_unit_xy[1])));
	write(1, "\n", 1);
}

void ft_hook(void* param)
{
	t_vars *vars;
	vars = param;

	// printf("vars->mini_unit_xy[0]%d, vars->mini_unit_xy[1]%d\n", vars->mini_unit_xy[0], vars->mini_unit_xy[1]);
	// printf("vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] + 1]==== %c\n", vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] + 1]);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);

	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
	{
		if(vars->map[(vars->cont_x_left)/ vars->len_char][(vars->cont_y_up+ vars->len_char + 1) / vars->len_char] != '1' &&\
			vars->map[(vars->cont_x_left + vars->len_char - 1)/ vars->len_char][(vars->cont_y_up + vars->len_char + 1) / vars->len_char] != '1')
		{
			vars->cont_y_up++;
			vars->mini_unit->instances[0].x += SPEEX;
		}
		ft_trace_line(vars);

		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->len_char);
		// debug(vars);
	}

	// 	// 	vars->mini_unit->instances[0].x += SPEEX;
	// 	// }
	// 	// debug(vars);
	// }
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
	// 	// vars->gun->instances[0].x-= 3;
	{

		if(vars->map[(vars->cont_x_left) / vars->len_char][(vars->cont_y_up  - 1) / vars->len_char] != '1' &&\
			vars->map[(vars->cont_x_left + vars->len_char - 1) / vars->len_char][(vars->cont_y_up - 1)/ vars->len_char] != '1')
		{
			vars->cont_y_up--;

			vars->mini_unit->instances[0].x -= SPEEX;
		}
		ft_trace_line(vars);

		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->len_char);
		// debug(vars);
	}
		// else if (vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] - 1] == '1' && vars->cont_x_left != 1)
		// {
		// 	if (vars->cont_x_left-- == 1)
		// 	{
		// 			vars->mini_unit_xy[1] -= 1;
		// 			vars->cont_x_left = vars->len_char;
				
		// 	}
		// 	vars->mini_unit->instances[0].x -= SPEEX;
		// }
		// debug(vars);

	// }
	
	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
	{	
		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->len_char);
		if(vars->map[(vars->cont_x_left - 1)/ vars->len_char][(vars->cont_y_up)/ vars->len_char] != '1' &&\
			vars->map[(vars->cont_x_left - 1) / vars->len_char][(vars->cont_y_up + vars->len_char - 1) / vars->len_char] != '1')
		{
			vars->cont_x_left--;

			vars->mini_unit->instances[0].y -= SPEEX;
		}
		// debug(vars);
		ft_trace_line(vars);

	}

	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
	{
		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->len_char);
		if(vars->map[(vars->cont_x_left + vars->len_char) / vars->len_char][(vars->cont_y_up + vars->len_char - 1) / vars->len_char] != '1' &&\
			vars->map[(vars->cont_x_left+ vars->len_char)/ vars->len_char][vars->cont_y_up  / vars->len_char] != '1')
		{
			vars->cont_x_left++;
			vars->mini_unit->instances[0].y += SPEEX;
		}
		ft_trace_line(vars);

		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->len_char);
		// debug(vars);


	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
	{
		ft_trace_line(vars);

	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
	{
		ft_trace_line(vars);

	}
}