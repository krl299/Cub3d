#include "cub3d.h"

int32_t	main(void)
{
	t_vars *vars;

	vars = malloc(sizeof(t_vars));
	*vars = (t_vars){};
// se crea estructura parse 
	vars->start_draw_x = 20;
	vars->start_draw_y = 50;
	vars->size_x = 1024;
	vars->size_y = 1024;
	vars->mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!vars->mlx)
        error();
	vars->gun_text = mlx_load_png("./gun.png");
	vars->gun = mlx_texture_to_image(vars->mlx, vars->gun_text);
	vars->texture = mlx_load_png("RGBA_Test_Square_1024.png");
	vars->texture2img = mlx_texture_to_image(vars->mlx, vars->texture);
	// ft_put_texture_pix(vars->texture, 0, 0);
	// vars->texture2img = mlx_texture_to_image(vars->mlx, vars->texture);
	// mlx_resize_image(vars->texture2img, 128, 128);
	// mlx_resize_image(vars->gun, 100, 100);
	vars->sky = mlx_new_image(vars->mlx, WIDTH + 60, HEIGHT + 60);
	vars->for_texture_print = mlx_new_image(vars->mlx, 512, 512);
	ft_create_sky(vars, vars->sky, HEIGHT, WIDTH, ft_get_rgba(100, 210, 250, 250));
	vars->image = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->image)
		error();
	uint32_t xy[2] = {100, 100};
	uint32_t s[2] = {100, 100};
	// printf("get time %f", mlx_get_time());

	// vars->image = mlx_texture_area_to_image(vars->mlx, vars->texture, xy , s);
	vars->texture2img = mlx_texture_to_image(vars->mlx, vars->texture);
	// ft_put_texture_pix(vars, vars->image, vars->texture, 0, 0);
	// ft_create_image(vars, vars->image, vars->size_x , vars->size_y, ft_get_rgba(200, 180, 100, 255));
	// ft_create_image(vars, vars->image, vars->size_x, vars->size_y, ft_get_rgba(200, 180, 100, 255));
	// ft_print_texture(vars, vars->texture2img);
	// printf("get time %f", mlx_get_time());

	if (mlx_image_to_window(vars->mlx, vars->sky, 0, -60) < 0)
        error();
		
	if (mlx_image_to_window(vars->mlx, vars->image, 0, 0) < 0)
        error();
	mlx_image_to_window(vars->mlx, vars->gun, 1024, 800);
	// ft_put_texture_pix(vars, vars->for_texture_print, vars->texture, 0, 0);
	// mlx_image_to_window(vars->mlx, vars->for_texture_print, 512, 512);
	mlx_image_to_window(vars->mlx, vars->texture2img,128, 128);
	mlx_image_to_window(vars->mlx, vars->texture2img,128 + vars->texture2img->width, 128);
	// mlx_image_to_window(vars->mlx, vars->texture2img,512,512);
	// mlx_image_to_window(vars->mlx, vars->texture2img, 0, 0);
	mlx_loop_hook(vars->mlx, ft_hook, vars);
	// mlx_mouse_hook(vars->mlx, &my_mouse_hook, vars);
	// mlx_mousefunc(vars->mlx, true);
	// mlx_scroll_hook(vars->mlx, my_scrollhook, vars);
	mlx_loop(vars->mlx);
	mlx_delete_image(vars->mlx, vars->image);
	mlx_terminate(vars->mlx);
	
	return (EXIT_SUCCESS);
}