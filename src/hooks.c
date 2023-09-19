#include "../includes/cub3d.h"

void debug(t_vars *vars)
{
	write(1,"vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] + 1] = ", 62);
	write(1, &vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] + 1], 1);
	write(1, "\n", 1);
	// write(1, )
	write(1, "y= ", 3);
	write(1, ft_itoa(vars->mini_unit_xy[0]), ft_strlen(ft_itoa(vars->mini_unit_xy[0])));
	write(1, ",x= ", 4);
	write(1, ft_itoa(vars->mini_unit_xy[1]), ft_strlen(ft_itoa(vars->mini_unit_xy[1])));
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
		if(vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] + 1] != '1')
		{
			if (vars->cont_x_left++ == vars->len_char)
			{
				vars->mini_unit_xy[1] += 1;
				vars->cont_x_left = 1;
			}

			vars->mini_unit->instances[0].x += SPEEX;
		}
		debug(vars);
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
		// vars->gun->instances[0].x-= 3;
	{

		if(vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] - 1] != '1')
		{

			if (vars->cont_x_left-- == 1)
			{
					vars->mini_unit_xy[1] -= 1;
					vars->cont_x_left = vars->len_char;
				
			}
			
				vars->mini_unit->instances[0].x -= SPEEX;
		}
		else if (vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] - 1] == '1' && vars->cont_x_left != 1)
		{
			if (vars->cont_x_left-- == 1)
			{
					vars->mini_unit_xy[1] -= 1;
					vars->cont_x_left = vars->len_char;
				
			}
			vars->mini_unit->instances[0].x -= SPEEX;
		}
		debug(vars);

	}
	
	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
	{	
		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->len_char);
		if(vars->map[vars->mini_unit_xy[0] - 1][vars->mini_unit_xy[1]] != '1')
		{
			if (vars->cont_y_up-- == 1)
			{
				vars->mini_unit_xy[0] -= 1;
				vars->cont_y_up = vars->len_char;
			}
			// printf("vars->cont_y	 = %d\n", vars->cont_y);


			vars->mini_unit->instances[0].y -= SPEEX;
		}
		debug(vars);

	}

	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
	{
		if(vars->map[vars->mini_unit_xy[0] + 1][vars->mini_unit_xy[1]] != '1')
		{
			if (vars->cont_y_down++ == vars->len_char)
			{
				vars->mini_unit_xy[0] += 1;
				vars->cont_y_down = 1;
			}
			// printf("vars->cont_y	 = %d\n", vars->cont_y);

			vars->mini_unit->instances[0].y += SPEEX;

		}
		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->len_char);
		debug(vars);


	}

}