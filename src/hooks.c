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

void ft_move_x(t_vars *vars, int corrector_x, int speed)
{
	float mem_x;
	float mem_y;
	mem_x = vars->map_vars->cont_x + vars->map_vars->len_char;
	mem_y = vars->map_vars->cont_y + 1;
	// if(vars->map_vars->map[(int)(mem_x - vars->map_vars->len_char/2)/ (vars->map_vars->len_char)][((int)mem_y+ vars->map_vars->len_char/2)/ vars->map_vars->len_char ] != '1' &&
	if(vars->map_vars->map[(int)((mem_x + cos(vars->map_vars->mini_u_angle)) - vars->map_vars->len_char/2)/ (vars->map_vars->len_char)][(int)((mem_y + sin(vars->map_vars->mini_u_angle))+ vars->map_vars->len_char/2)/ vars->map_vars->len_char + corrector_x] != '1')
		vars->map_vars->cont_y += 1 * corrector_x * speed;
	// vars->mini_unit->instances[0].x += speed * corrector_x;
}
void ft_move_y(t_vars *vars, int corrector_y, int speed)
{
		float mem_x;
	float mem_y;
	mem_x = vars->map_vars->cont_x + vars->map_vars->len_char;
	mem_y = vars->map_vars->cont_y + 1;
// if(vars->map_vars->map[(int)(mem_x - vars->map_vars->len_char/2)/ (vars->map_vars->len_char) + 1][((int)mem_y+ vars->map_vars->len_char/2)/ vars->map_vars->len_char] != '1' &&
		if(vars->map_vars->map[(int)(mem_x - vars->map_vars->len_char/2)/ (vars->map_vars->len_char) + corrector_y][((int)mem_y+ vars->map_vars->len_char/2)/ vars->map_vars->len_char] != '1')
	vars->map_vars->cont_x += 1 * corrector_y * speed;
	// vars->mini_unit->instances[0].y += speed * corrector_y;
}

void ft_2yx(t_vars *vars, int corector_x, int corector_y)
{
	static int fx = 0;
		ft_move_y(vars, corector_y, 2);
		ft_move_x(vars, corector_x, 1);
		if (fx++ % 2 == 0)
			ft_trace_line(vars);


}

void ft_yx(t_vars *vars, int corector_x, int corector_y)
{
	static int fx = 0;

		ft_move_x(vars, corector_x, 1);
		ft_move_y(vars, corector_y, 1);
		if (fx++ % 2 == 0)
			ft_trace_line(vars);



}

void ft_2xy(t_vars *vars, int corector_x, int corector_y)
{
{
	static int fx = 0;

		ft_move_x(vars, corector_x, 2);
		ft_move_y(vars, corector_y, 1);
		if (fx++ % 2 == 0)
			{
			ft_trace_line(vars);
			// fx = 0;
			}
		// ft_trace_line(vars);	


}

}
void ft_move(t_vars * vars, int corector_x, int corector_y)
{
	if ((vars->map_vars->go_angle >= 31 || vars->map_vars->go_angle <= 1)\
		|| (vars->map_vars->go_angle > 15 && vars->map_vars->go_angle <=17))
		{
			ft_move_y(vars, corector_y, 2);
			ft_trace_line(vars);
		}
		else if ((vars->map_vars->go_angle > 23 && vars->map_vars->go_angle <= 25)\
		|| 	(vars->map_vars->go_angle > 7 && vars->map_vars->go_angle <= 9))
			{
			ft_move_x(vars, corector_x, 2);
			ft_trace_line(vars);	
			}
		else if ((vars->map_vars->go_angle > 1 && vars->map_vars->go_angle <= 3)\
		|| (vars->map_vars->go_angle > 17 && vars->map_vars->go_angle <= 19)\
		|| (vars->map_vars->go_angle > 29 && vars->map_vars->go_angle < 31)\
		|| (vars->map_vars->go_angle > 13 && vars->map_vars->go_angle <= 15))
		{
			ft_2yx(vars, corector_x, corector_y);
		}
		else if ((vars->map_vars->go_angle > 3 && vars->map_vars->go_angle <= 5)\
		|| (vars->map_vars->go_angle > 19 && vars->map_vars->go_angle <= 21)\
		|| (vars->map_vars->go_angle > 27 && vars->map_vars->go_angle <= 29)\
		|| (vars->map_vars->go_angle > 11 && vars->map_vars->go_angle <= 13))
		{
			ft_yx(vars, corector_x, corector_y);
		}
		else if ((vars->map_vars->go_angle > 5 && vars->map_vars->go_angle <= 7)\
		|| (vars->map_vars->go_angle > 21 && vars->map_vars->go_angle <= 23)\
		|| (vars->map_vars->go_angle > 9 && vars->map_vars->go_angle <= 11)\
		|| (vars->map_vars->go_angle > 25 && vars->map_vars->go_angle <= 27))
		{
			ft_2xy(vars, corector_x, corector_y);
		}
		if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
		{	
			vars->map_vars->mini_u_angle += ONE_DEG;
			ft_trace_line(vars);
		}
		if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
		{	
			
			vars->map_vars->mini_u_angle -= ONE_DEG;
			ft_trace_line(vars);	

		}
}
void ft_hook(void* param)
{
	t_vars *vars;

	static int fx = 0;
	static int fy = 0;
	int corector_x = 1;
	int corector_y = 1;
	float sect_calc;
	vars = param;
			if (vars->map_vars->mini_u_angle >= M_PI * 2)
		vars->map_vars->mini_u_angle = 0.0000000001;
			if (vars->map_vars->mini_u_angle < 0.0000000001)
		vars->map_vars->mini_u_angle =  M_PI * 2;
	if (vars->map_vars->go_angle > 8 && vars->map_vars->go_angle <= 25)
		corector_y = -1;
	// if (vars->map_vars->go_angle >= 17 && vars->map_vars->go_angle <= 23)
	// {
	// 	corector_x = -1;
	// 	corector_y = -1;
	// }
	if (vars->map_vars->go_angle >16 && vars->map_vars->go_angle <= 32)
		corector_x = -1;
	// if (mlx_is_key_down(vars->mlx, MLX_KEY_UP))
	sect_calc = vars->map_vars->go_angle;

	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_DOWN))
	{
		corector_x *= -1;
		corector_y *= -1;
		ft_move(vars, corector_x, corector_y);

	}

	if (mlx_is_key_down(vars->mlx, MLX_KEY_UP))
	{

					// vars->map_vars->map[(int)(mem_x - vars->map_vars->len_char /2) / vars->map_vars->len_char + 1][((int)mem_y + vars->map_vars->len_char /2) / vars->map_vars->len_char] != '1' &&\
					// vars->map_vars->map[(int)(mem_x - vars->map_vars->len_char /2) / vars->map_vars->len_char][((int)mem_y + vars->map_vars->len_char /2) / vars->map_vars->len_char + 1] != '1')
		ft_move(vars, corector_x, corector_y);

		debug(vars);
		// if (vars->steps == 2)
		// {
		// 	vars->steps = 0;
		// }
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
	{
		vars->map_vars->mini_u_angle += ONE_DEG * 3;
		ft_trace_line(vars);

	}
	else if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
	{
		vars->map_vars->mini_u_angle -= ONE_DEG * 3;
		ft_trace_line(vars);

	}

	
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





	// // printf("instances y = %d", vars->mini_unit->instances[0].y/vars->map_vars->len_char);
		// // if(vars->map_vars->map[(vars->map_vars->cont_x - 1)/ vars->map_vars->len_char][(vars->map_vars->cont_y)/ vars->map_vars->len_char] != '1' &&\
		// // 	vars->map_vars->map[(vars->map_vars->cont_x - 1) / vars->map_vars->len_char][(vars->map_vars->cont_y + vars->map_vars->len_char - 1) / vars->map_vars->len_char] != '1')
		// // {
		// if(vars->map_vars->go_angle > 24 && vars->map_vars->go_angle <= 32)
		// {
		// 	vars->map_vars->cont_x++;
		// 	vars->mini_unit->instances[0].y += SPEEX;
		// 	vars->map_vars->cont_y--;
		// 	vars->mini_unit->instances[0].x -= SPEEX;
		// 	if(vars->map_vars->go_angle > 24 && vars->map_vars->go_angle <= 28)
		// 	{
		// 		vars->map_vars->cont_y--;
		// 		vars->mini_unit->instances[0].x -= SPEEX;
		// 	}
		// 	else
		// 	{
		// 		vars->map_vars->cont_x++;
		// 		vars->mini_unit->instances[0].y += SPEEX;
		// 	}
		// }
		// else if(vars->map_vars->go_angle > 16  && vars->map_vars->go_angle <= 24)
		// {
		// 	vars->map_vars->cont_x--;
		// 	vars->mini_unit->instances[0].y -= SPEEX;
		// 	vars->map_vars->cont_y--;
		// 	vars->mini_unit->instances[0].x -= SPEEX;
		// 	if(vars->map_vars->go_angle > 16 && vars->map_vars->go_angle <= 20)
		// 	{
		// 		vars->map_vars->cont_x--;
		// 		vars->mini_unit->instances[0].y -= SPEEX;
		// 	}
		// 	else
		// 	{
		// 		vars->map_vars->cont_y--;
		// 		vars->mini_unit->instances[0].x -= SPEEX;
		// 	}
		// }
		// else if(vars->map_vars->go_angle > 8  && vars->map_vars->go_angle <= 16)
		// {
		// 	vars->map_vars->cont_x--;
		// 	vars->mini_unit->instances[0].y -= SPEEX;
		// 	vars->map_vars->cont_y++;
		// 	vars->mini_unit->instances[0].x += SPEEX;
		// 	if(vars->map_vars->go_angle > 12 && vars->map_vars->go_angle <= 16)
		// 	{
		// 		vars->map_vars->cont_x--;
		// 		vars->mini_unit->instances[0].y -= SPEEX;
		// 	}
		// 	else
		// 	{
		// 		vars->map_vars->cont_x++;
		// 		vars->mini_unit->instances[0].x += SPEEX;
		// 	}
		// }
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