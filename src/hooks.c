#include "../includes/cub3d.h"


void ft_hook(void* param)
{
	t_vars *vars;
	vars = param;

	// printf("vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] + 1]==== %c\n", vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] + 1]);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);

	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
	{
		if(vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1] + 1] != '1')
		{
			if (vars->cont_x++ == vars->len_char)
			{
				vars->mini_unit_xy[1] += 1;
				vars->cont_x = 1;
			}

			vars->mini_unit->instances[0].x += SPEEX;
		}

	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
		// vars->gun->instances[0].x-= 3;
	{

		if(vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1]] != '1')
		{

			if (vars->cont_x-- == 1)
			{
				vars->mini_unit_xy[1] -= 1;
				vars->cont_x = vars->len_char;
			}
				vars->mini_unit->instances[0].x -= SPEEX;
		}
	}
		// mlx_resize_image(vars->texture2img, WIDTH-5, HEIGHT - 1);
	printf("vars->mini_unit_xy[0]%d, vars->mini_unit_xy[1]%d\n", vars->mini_unit_xy[0], vars->mini_unit_xy[1]);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
	{	
		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->len_char);
		if(vars->map[vars->mini_unit_xy[0]][vars->mini_unit_xy[1]] != '1')
		{
			if (vars->cont_y-- == 1)
			{
				vars->mini_unit_xy[0] -= 1;
				vars->cont_y = vars->len_char;
			}
			vars->mini_unit->instances[0].y -= SPEEX;
		}
	}

	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
	{
		if(vars->map[vars->mini_unit_xy[0] + 1][vars->mini_unit_xy[1]] != '1')
		{
			if (vars->cont_y++ == vars->len_char)
			{
				vars->mini_unit_xy[0] += 1;
				vars->cont_y = 1;
			}
			vars->mini_unit->instances[0].y += SPEEX;
		}
		// printf("instances y = %d", vars->mini_unit->instances[0].y/vars->len_char);


	}
}