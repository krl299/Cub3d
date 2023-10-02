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
			if (vars->map_vars->mini_u_angle >= M_PI * 2)
		vars->map_vars->mini_u_angle = 0.0000000001;
			if (vars->map_vars->mini_u_angle < 0.0000000001)
		vars->map_vars->mini_u_angle =  M_PI * 2;


	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);


	else if (mlx_is_key_down(vars->mlx, MLX_KEY_UP))
	{	
		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->map_vars->len_char);
		// if(vars->map_vars->map[(vars->map_vars->cont_x - 1)/ vars->map_vars->len_char][(vars->map_vars->cont_y)/ vars->map_vars->len_char] != '1' &&\
		// 	vars->map_vars->map[(vars->map_vars->cont_x - 1) / vars->map_vars->len_char][(vars->map_vars->cont_y + vars->map_vars->len_char - 1) / vars->map_vars->len_char] != '1')
		// {
		if(vars->map_vars->go_angle > 24 && vars->map_vars->go_angle <= 32)
		{
			vars->map_vars->cont_x++;
			vars->mini_unit->instances[0].y += SPEEX;
			vars->map_vars->cont_y--;
			vars->mini_unit->instances[0].x -= SPEEX;
			if(vars->map_vars->go_angle > 24 && vars->map_vars->go_angle <= 28)
			{
				vars->map_vars->cont_y--;
				vars->mini_unit->instances[0].x -= SPEEX;
			}
			else
			{
				vars->map_vars->cont_x++;
				vars->mini_unit->instances[0].y += SPEEX;
			}
		}
		else if(vars->map_vars->go_angle > 16  && vars->map_vars->go_angle <= 24)
		{
			vars->map_vars->cont_x--;
			vars->mini_unit->instances[0].y -= SPEEX;
			vars->map_vars->cont_y--;
			vars->mini_unit->instances[0].x -= SPEEX;
			if(vars->map_vars->go_angle > 16 && vars->map_vars->go_angle <= 20)
			{
				vars->map_vars->cont_x--;
				vars->mini_unit->instances[0].y -= SPEEX;
			}
			else
			{
				vars->map_vars->cont_y--;
				vars->mini_unit->instances[0].x -= SPEEX;
			}
		}
		else if(vars->map_vars->go_angle > 8  && vars->map_vars->go_angle <= 16)
		{
			vars->map_vars->cont_x--;
			vars->mini_unit->instances[0].y -= SPEEX;
			vars->map_vars->cont_y++;
			vars->mini_unit->instances[0].x += SPEEX;
			if(vars->map_vars->go_angle > 12 && vars->map_vars->go_angle <= 16)
			{
				vars->map_vars->cont_x--;
				vars->mini_unit->instances[0].y -= SPEEX;
			}
			else
			{
				vars->map_vars->cont_x++;
				vars->mini_unit->instances[0].x += SPEEX;
			}
		}
		// if (vars->map_vars->go_angle >= 25 || vars->map_vars->go_angle < 8)
		// {
		// 	vars->map_vars->cont_x++;
		// 	vars->mini_unit->instances[0].y += SPEEX;
		// }
		// if (vars->map_vars->go_angle > 0 && vars->map_vars->go_angle < 3)
		// {
		// 	vars->map_vars->cont_x++;
		// 	vars->mini_unit->instances[0].y += SPEEX;
		// }
		// if (vars->map_vars->go_angle >= 3 && vars->map_vars->go_angle < 5)
		// {
		// 	vars->map_vars->cont_x++;
		// 	vars->mini_unit->instances[0].y += SPEEX;
		// 	vars->map_vars->cont_y--;
		// 	vars->mini_unit->instances[0].x -= SPEEX;
		// }

		// if (vars->map_vars->go_angle > 16 && vars->map_vars->go_angle <= 32)
		// {
		// 	vars->map_vars->cont_y--;
		// 	vars->mini_unit->instances[0].x -= SPEEX;

		// }
		// if (vars->map_vars->go_angle >= 8 && vars->map_vars->go_angle < 25)
		// {
		// 	vars->map_vars->cont_x--;
		// 	vars->mini_unit->instances[0].y -= SPEEX;
		// }
		// if (vars->map_vars->go_angle > 0 && vars->map_vars->go_angle <= 16)
		// {
		// 	vars->map_vars->cont_y++;
		// 	vars->mini_unit->instances[0].x += SPEEX;
		// }	
		if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
			vars->map_vars->mini_u_angle += 0.04;
		if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
			vars->map_vars->mini_u_angle -= 0.04;

		debug(vars);
		ft_trace_line(vars);
	}

	// else if (mlx_is_key_down(vars->mlx, MLX_KEY_DOWN))
	// {
		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->map_vars->len_char);
		// if((vars->map_vars->map[(vars->map_vars->cont_x + vars->map_vars->len_char) / vars->map_vars->len_char][(vars->map_vars->cont_y + vars->map_vars->len_char - 1) / vars->map_vars->len_char] != '1' &&\
		// 	vars->map_vars->map[(vars->map_vars->cont_x+ vars->map_vars->len_char)/ vars->map_vars->len_char][vars->map_vars->cont_y  / vars->map_vars->len_char] != '1') || \
		// 	(vars->map_vars->map[(vars->map_vars->cont_x - 1)/ vars->map_vars->len_char][(vars->map_vars->cont_y)/ vars->map_vars->len_char] != '1' &&\
		// 	vars->map_vars->map[(vars->map_vars->cont_x - 1) / vars->map_vars->len_char][(vars->map_vars->cont_y + vars->map_vars->len_char - 1) / vars->map_vars->len_char] != '1'))
		// {
	// 		if (vars->map_vars->go_angle > 25 || vars->map_vars->go_angle < 16)
	// 		{
	// 			vars->map_vars->cont_x--;
	// 			vars->mini_unit->instances[0].y -= SPEEX;
	// 			if (vars->map_vars->go_angle > 25)
	// 			{
	// 				vars->map_vars->cont_y++;
	// 				vars->mini_unit->instances[0].x += SPEEX;
	// 			}
	// 			else
	// 			{
	// 				vars->map_vars->cont_y--;
	// 				vars->mini_unit->instances[0].x -= SPEEX;
	// 			}
	// 		}
	// 		else 
	// 		{
	// 			vars->map_vars->cont_x++;
	// 			vars->mini_unit->instances[0].y += SPEEX;
	// 		}
	// 	// }
	// 	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
	// 		vars->map_vars->mini_u_angle += 0.04;
	// 	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
	// 		vars->map_vars->mini_u_angle -= 0.04;

	// 	ft_trace_line(vars);
	// 	debug(vars);
	// }
	else if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
	{
		vars->map_vars->mini_u_angle += 0.04;
		ft_trace_line(vars);

	}
	else if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
	{
		vars->map_vars->mini_u_angle -= 0.04;
		ft_trace_line(vars);

	}



		// if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
		// {
		// 	if(vars->map_vars->map[(vars->map_vars->cont_x) / vars->map_vars->len_char][(vars->map_vars->cont_y  - 1) / vars->map_vars->len_char] != '1' &&\
		// 		vars->map_vars->map[(vars->map_vars->cont_x + vars->map_vars->len_char - 1) / vars->map_vars->len_char][(vars->map_vars->cont_y - 1)/ vars->map_vars->len_char] != '1')
		// 	{
		// 		vars->map_vars->cont_y--;
		// 		vars->mini_unit->instances[0].x -= SPEEX;
		// 	}
		// }
		// if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
		// {
		// 	if(vars->map_vars->map[(vars->map_vars->cont_x)/ vars->map_vars->len_char][(vars->map_vars->cont_y) / vars->map_vars->len_char + 1] != '1' &&\
		// 		vars->map_vars->map[(vars->map_vars->cont_x + vars->map_vars->len_char - 1)/ vars->map_vars->len_char][(vars->map_vars->cont_y + vars->map_vars->len_char) / vars->map_vars->len_char] != '1')
		// 	{
		// 		vars->map_vars->cont_y++;
		// 		vars->mini_unit->instances[0].x += SPEEX;
		// 	}
		// }

			// if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
		// {
		// 	if(vars->map_vars->map[(vars->map_vars->cont_x) / vars->map_vars->len_char][(vars->map_vars->cont_y  - 1) / vars->map_vars->len_char] != '1' &&\
		// 		vars->map_vars->map[(vars->map_vars->cont_x + vars->map_vars->len_char - 1) / vars->map_vars->len_char][(vars->map_vars->cont_y - 1)/ vars->map_vars->len_char] != '1')
		// 	{
		// 		vars->map_vars->cont_y--;
		// 		vars->mini_unit->instances[0].x -= SPEEX;
		// 	}
		// }
	// 	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
	// 	{
	// 		if(vars->map_vars->map[(vars->map_vars->cont_x)/ vars->map_vars->len_char][(vars->map_vars->cont_y) / vars->map_vars->len_char + 1] != '1' &&\
	// 			vars->map_vars->map[(vars->map_vars->cont_x + vars->map_vars->len_char - 1)/ vars->map_vars->len_char][(vars->map_vars->cont_y + vars->map_vars->len_char) / vars->map_vars->len_char] != '1')
	// 		{
	// 			vars->map_vars->cont_y++;
	// 			vars->mini_unit->instances[0].x += SPEEX;
	// 		}
	// 	}
	// 	else if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
	// {																					//+ 1
	// 	if(vars->map_vars->map[(vars->map_vars->cont_x)/ vars->map_vars->len_char][(vars->map_vars->cont_y) / vars->map_vars->len_char + 1] != '1' &&\
	// 		vars->map_vars->map[(vars->map_vars->cont_x + vars->map_vars->len_char - 1)/ vars->map_vars->len_char][(vars->map_vars->cont_y + vars->map_vars->len_char) / vars->map_vars->len_char] != '1')
	// 	{
	// 		vars->map_vars->cont_y++;
	// 		vars->mini_unit->instances[0].x += SPEEX;
	// 	}
	// 	ft_trace_line(vars);
	// 	debug(vars);
	// }

	// else if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
	// {

	// 	if(vars->map_vars->map[(vars->map_vars->cont_x) / vars->map_vars->len_char][(vars->map_vars->cont_y  - 1) / vars->map_vars->len_char] != '1' &&\
	// 		vars->map_vars->map[(vars->map_vars->cont_x + vars->map_vars->len_char - 1) / vars->map_vars->len_char][(vars->map_vars->cont_y - 1)/ vars->map_vars->len_char] != '1')
	// 	{
	// 		vars->map_vars->cont_y--;

	// 		vars->mini_unit->instances[0].x -= SPEEX;
	// 	}
	// 	ft_trace_line(vars);
	// 	debug(vars);
	// }
}