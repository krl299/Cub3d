#include "../includes/cub3d.h"


void ft_hook(void* param)
{
	t_vars *vars;
	vars = param;
	
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	// if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT_SHIFT))
	// {
	// }
	// if (mlx_is_key_down(vars->mlx, MLX_KEY_SPACE))
	// {
	// }
	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
	{
		static int count = 0;
		vars->mini_unit->instances[0].x += SPEEX;

	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
		// vars->gun->instances[0].x-= 3;
	{
		vars->mini_unit->instances[0].x -= SPEEX;
	}
		// mlx_resize_image(vars->texture2img, WIDTH-5, HEIGHT - 1);

	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
	{	
		vars->mini_unit->instances[0].y -= SPEEX;
	}

	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
	{
		vars->mini_unit->instances[0].y += SPEEX;

	}
}