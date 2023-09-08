


// // -----------------------------------------------------------------------------
// // Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// // See README in the root project for more information.
// // -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "MLX42/include/MLX42/MLX42.h"

// #define WIDTH 512
// #define HEIGHT 512

// static mlx_image_t* image;

// // -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	for (int32_t i = 0; i < image->width; ++i)
// 	{
// 		for (int32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

// // -----------------------------------------------------------------------------

// int32_t main(int32_t argc, const char* argv[])
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }





// Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
// #define BPP sizeof(int32_t)

// int32_t	main(void)
// {
//     // Init mlx with a canvas size of 256x256 and the ability to resize the window.
//     mlx_t* mlx = mlx_init(256, 256, "MLX42", true);
    
//     if (!mlx) exit(EXIT_FAILURE);

//     // Create a 128x128 image.
//     mlx_image_t* img = mlx_new_image(mlx, 128, 128);

//     // Set the channels of each pixel in our image to the maximum byte value of 255. 
//     memset(img->pixels, 255, img->width * img->height * BPP);

//     // Draw the image at coordinate (0, 0).
//     mlx_image_to_window(mlx, img, 0, 0);

//     // Run the main loop and terminate on quit.  
//     mlx_loop(mlx);
//     mlx_terminate(mlx);

//     return (EXIT_SUCCESS);
// }


// #include <stdlib.h>
// #include <stdio.h>
// #include <stdio.h>
// #include "MLX42/MLX42.h"
// #define WIDTH 720
// #define HEIGHT 480

// void my_scrollhook(double xdelta, double ydelta, void* param)
// {
// 	// Simple up or down detection.
// 	if (ydelta > 0)
// 		puts("Up!");
// 	else if (ydelta < 0)
// 		puts("Down!");
	
// 	// Can also detect a mousewheel that goes along the X (e.g: MX Master 3)
// 	if (xdelta < 0)
// 		puts("Sliiiide to the left!");
// 	else if (xdelta > 0)
// 		puts("Sliiiide to the right!");
// }

// int32_t	main(void)
// {
// 	mlx_t* mlx;

// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 		return (EXIT_FAILURE);

// 	mlx_scroll_hook(mlx, &my_scrollhook, NULL);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
// #define WIDTH 720
// #define HEIGHT 480

// void my_keyhook(mlx_key_data_t keydata, void* param)
// {
// 	// If we PRESS the 'J' key, print "Hello".
// 	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
// 		puts("Hello ");

// 	// If we RELEASE the 'K' key, print "World".
// 	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
// 		puts("World");

// 	// If we HOLD the 'L' key, print "!".
// 	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
// 		puts("!");
// }

// int32_t	main(void)
// {
// 	mlx_t* mlx;

// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 		return (EXIT_FAILURE);

// 	mlx_key_hook(mlx, &my_keyhook, NULL);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }


// static void error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// int32_t	main(void)
// {
// 	// Start mlx
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
// 	if (!mlx)
//         error();

// 	// Try to load the file
// 	mlx_texture_t* texture = mlx_load_png("./temp/sus.png");
// 	if (!texture)
//         error();
	
// 	// Convert texture to a displayable image
// 	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
// 	if (!img)
//         error();

// 	// Display the image
// 	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
//         error();

// 	mlx_loop(mlx);

// 	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
// 	mlx_delete_image(mlx, img);
// 	mlx_delete_texture(texture);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

#include <unistd.h>

#define WIDTH 1024
#define HEIGHT 1024



static mlx_image_t* image;
static mlx_image_t* image2;
static int size = 512;
static int size2 = 512;

void ft_create_image(mlx_image_t *img, int size, int size2, unsigned int col)
{
	int counter = 100;
	int counter2 = 300;
	// int size_loc = size/2;
	while (counter < size)
	{
		counter2 = 300;
		while(counter2 < size)
		{
			mlx_put_pixel(img, counter, counter2, col);
			counter2++;
		}
		// mlx_put_pixel(img, counter, counter, 0xFFFFFFFF);
		counter++;
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;
	int static jump = 0;
	int static sit = 0;
	if (jump)
	{
		image->instances[0].y -= 60;
		jump = 0;
	}
	if (sit)
	{
		image->instances[0].y += 20;
		sit = 0;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		sit = 1;
		image->instances[0].y -= 20;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		jump = 1;
		image->instances[0].y += 60;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		size += 1;
		size2 += 1;
		// mlx_delete_image(mlx, image);
		int x = image->instances[0].x;
		int y = image->instances[0].y;
		mlx_delete_image(mlx, image);
		image = mlx_new_image(mlx, size, size2);
		ft_create_image(image, size, size2, 255);
		mlx_image_to_window(mlx, image, x, y);
	}

	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		size -= 1;
		size2 -= 1;
		// mlx_delete_image(mlx, image);
		int x = image->instances[0].x;
		int y = image->instances[0].y;
		mlx_delete_image(mlx, image);
		image = mlx_new_image(mlx, size, size2);
		ft_create_image(image, size, size2, 255);
		mlx_image_to_window(mlx, image, x, y);
	}

	
}

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// int counter()
// {
// 	static int i = 0;
// 	return (i++);
// }

int32_t	main(void)
{
	// Start mlx
	int counter = 20;
	int counter2 = 50;

	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
        error();

	// Create a new image
	image = mlx_new_image(mlx, 512, 512);
	if (!image)
		error();

	ft_create_image(image, size, size2, 255);

	// mlx_put_pixel(img, 0, 0, 0xFFFFFFFF);

	// Display an instance of the image
	if (mlx_image_to_window(mlx, image, 0, 0) < 0)
        error();

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, image);
	mlx_terminate(mlx);
	
	return (EXIT_SUCCESS);
}