
#include "cub3d.h"

int ft_get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
void ft_create_sky(t_vars *vars, mlx_image_t *img, int size, int size2, unsigned int col)
{
	int start_draw_x = 0;
	int start_draw_y = 0;
	unsigned int start_color = col;
	// int size_loc = size/2;
	while (start_draw_x < WIDTH)
	{
		start_draw_y = 0;
		while(start_draw_y < HEIGHT + 59)
		{
			if (start_draw_y > (HEIGHT + 59) / 2)
				col = ft_get_rgba(100,100,100,100);
			else
				col = start_color;
			mlx_put_pixel(img, start_draw_x, start_draw_y, col);
			start_draw_y++;
		}
		// mlx_put_pixel(img, start_draw_x, start_draw_x, 0xFFFFFFFF);
		start_draw_x++;
	}
}
u_int32_t ft_get_text_col(t_vars *vars)
{
	static int num = 0;
	static int c = 24;
	static int c2 = 4;
	u_int32_t col;


	col = ft_get_rgba(vars->texture->pixels[num], vars->texture->pixels[num + 1], vars->texture->pixels[num +2],  vars->texture->pixels[num + 3]);
	num+=4;
	if (num >= vars->texture->width * vars->texture->height)
		num = 0;
	return(col);
}
void ft_create_image(t_vars *vars, mlx_image_t *img, int size, int size2, unsigned int col)
{
	int start_draw_x = 0;
	int start_draw_y = 200;
	int h = HEIGHT  - 100;
	int w = WIDTH;
	// int size_loc = size/2;
	int r = 100;
	int g = 200;
	int b = 150;
	int frst_part_x = 1;
	int frst_part_y = 1;
	int num = 0;
	int coef = 0;
	// col = ft_get_rgba(vars->texture->pixels[num], vars->texture->pixels[num + 1], vars->texture->pixels[num +2],  vars->texture->pixels[num + 3]);

	while( start_draw_x < size)
	{
		num+=4 * coef;
		frst_part_y = start_draw_x;
		while (frst_part_y < h - 1)
		{
			// printf("start_draw_y = %d\n", frst_part_y);
			mlx_put_pixel(img, start_draw_x, frst_part_y++, ft_get_rgba(vars->texture->pixels[num], vars->texture->pixels[num + 1], vars->texture->pixels[num +2],  vars->texture->pixels[num + 3]));
			num+=4;
		}
		// printf("start_draw_x = %d\n", start_draw_x);
		// printf("h= %d\n", h);
		coef++;
		h--;
		start_draw_x++;
	}
	frst_part_x = start_draw_x;
	col = ft_get_rgba(255, 255, 255, 255);
	while (start_draw_x < WIDTH)
	{
		start_draw_y = frst_part_x;
		while(start_draw_y < frst_part_y)
		{
			mlx_put_pixel(img, start_draw_x, start_draw_y, ft_get_text_col(vars));
			start_draw_y++;

		}
		col = ft_get_rgba(r, g, b, 255);

		start_draw_x++;
	}





			// r++;
		// 	if (r == 255 || g == 200 || b == 255)
		// 	{
		// 		if (r == 255)
		// 		{
		// 			r = 0;
		// 			g++;
		// 		}
		// 		else if (g == 200)
		// 		{
		// 			g = 0;
		// 			b++;
		// 		}
		// 		else if (b == 255)
		// 		{
		// 			r = 0;
		// 			g = 0;
		// 			b = 0;
		// 		}
		// 	}
		// }
		// mlx_put_pixel(img, start_draw_x, start_draw_x, 0xFFFFFFFF);
}

void ft_hook(void* param)
{
	t_vars *vars;
	vars = param;
	int static jump = 0;
	int static sit = 0;
	if (jump)
	{
		vars->texture2img->instances[0].y -= 60;
		vars->sky->instances[0].y -= 60;
		jump = 0;
	}
	if (sit)
	{
		vars->texture2img->instances[0].y += 20;
		vars->sky->instances[0].y += 20;
		sit = 0;
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT_SHIFT))
	{
		sit = 1;
		vars->texture2img->instances[0].y -= 20;
		vars->sky->instances[0].y -= 20;
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_SPACE))
	{
		jump = 1;
		vars->texture2img->instances[0].y += 60;
		vars->sky->instances[0].y += 60;
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
	{
		static int count = 0;
		if (count == 20)
			count = 0;
		vars->texture2img->instances[0].x -= SPEEX;
		// vars->gun->instances[0].x+= 3;
		mlx_delete_image(vars->mlx, vars->gun);
		vars->gun = mlx_texture_to_image(vars->mlx, vars->gun_text);
		mlx_resize_image(vars->gun, vars->gun->width + count, vars->gun->height + count);
		mlx_image_to_window(vars->mlx, vars->gun, 1024 + count, 800 - count);
		count++;
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
		// vars->gun->instances[0].x-= 3;
	{
		static int count = 0;
		if (count == 20)
			count = 0;
		vars->texture2img->instances[0].x += SPEEX;
		mlx_delete_image(vars->mlx, vars->gun);
		vars->gun = mlx_texture_to_image(vars->mlx, vars->gun_text);
		mlx_resize_image(vars->gun, vars->gun->width + count, vars->gun->height + count);
		mlx_image_to_window(vars->mlx, vars->gun, 1024 + count, 800 - count);
		count++;
	}
		// mlx_resize_image(vars->texture2img, WIDTH-5, HEIGHT - 1);

	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
	{
		vars->size_x += SPEEX;
		vars->size_y+=SPEEY;
		vars->save_pos_x = vars->texture2img->instances[0].x;
		vars->save_pos_y = vars->texture2img->instances[0].y;
		mlx_delete_image(vars->mlx, vars->texture2img);
		vars->texture2img = mlx_texture_to_image(vars->mlx, vars->texture);
		// vars->texture2img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
		mlx_resize_image(vars->texture2img, vars->size_x, vars->size_y);

		// ft_create_image(vars, vars->texture2img, vars->size_x , vars->size_y,  ft_get_rgba(200, 180, 100, 255));
		mlx_image_to_window(vars->mlx, vars->texture2img, vars->save_pos_x, vars->save_pos_y );
		

	}

	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
	{
		vars->size_x -= SPEEX;
		vars->size_y -= SPEEY;
		vars->save_pos_x = vars->texture2img->instances[0].x;
		vars->save_pos_y = vars->texture2img->instances[0].y;
		mlx_delete_image(vars->mlx, vars->texture2img);
		vars->texture2img = mlx_texture_to_image(vars->mlx, vars->texture);
		// ft_create_image(vars, vars->texture2img, vars->size_x , vars->size_y, ft_get_rgba(200, 180, 100, 255));
		mlx_resize_image(vars->texture2img, vars->size_x, vars->size_y);
		mlx_image_to_window(vars->mlx, vars->texture2img, vars->save_pos_x, vars->save_pos_y);

	}

	
}

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
void my_mouse_hook(int button, int x, int y, void* param)
{
	puts("Mouse clicked!");
	
}
// mlx_mousefunc *my_scrollhook(double xdelta, double ydelta, void* param)
// {
// 	// Simple up or down detection.
// 	if (ydelta > 0)
// 		printf("Scrolling up by %f\n", ydelta);
// 	else if (ydelta < 0)
// 		printf("Scrolling up by %f\n", ydelta);
		
	
// 	// Can also detect a mousewheel that goes along the X (e.g: MX Master 3)
// 	if (xdelta < 0)
// 		puts("Sliiiide to the left!");
// 	else if (xdelta > 0)
// 		puts("Sliiiide to the right!");
// }
// void ft_print_texture(t_vars *vars, mlx_image_t *texture)
// {
// 	int i = 0;
// 	int j = 0;
// 	while (i < texture->height)
// 	{
// 		j = 0;
// 		while (j < texture->width)
// 		{
// 			mlx_put_pixel(vars->image, j, i, texture->pixels[i * texture->width + j]);
// 			j++;
// 		}
// 		i++;
// 	}
// }



void ft_put_texture_pix(t_vars *vars, mlx_image_t *img, mlx_texture_t *texture, int x, int y)
{
	int i = 0;
	int j = 0;
	int start_draw_x = x;
	int start_draw_y = y;
	printf("texture->width = %d\n", texture->width);
	printf("texture->height = %d\n", texture->height);
	u_int32_t col = 0;
	int num = 0;
	while(start_draw_x < texture->width)
	{
		start_draw_y = 0;

		while (start_draw_y < texture->height)
		{
			// col = texture->pixels[i + j * texture->width];
			// printf("pixels [%d] = %d\n", num ,texture->pixels[num]);
			mlx_put_pixel(img, start_draw_y, start_draw_x, ft_get_rgba(texture->pixels[num], texture->pixels[num + 1], texture->pixels[num +2],  texture->pixels[num + 3]));
			num+=4;
			start_draw_y++;
		}
		// num+=4;
		start_draw_x++;
		i++;
	}
	// while (i < texture->height)
	// {
	// 	j = 0;
	// 	while (j < texture->width)
	// 	{
	// 		printf("texture pix%d\n", texture->pixels[i + j * texture->width]);
	// 		mlx_put_pixel(img, i, j, texture->pixels[i + j * texture->width]);
	// 		j++;
	// 	}
	// 	start_draw_y++;
	// 	// start_draw_x = x;
	// 	i++;
	// }
}
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