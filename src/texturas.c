/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:37:46 by mandriic          #+#    #+#             */
/*   Updated: 2023/10/13 13:37:46 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
			mlx_put_pixel(img, start_draw_y, start_draw_x, ft_get_rgba(texture->pixels[num], texture->pixels[num + 1], texture->pixels[num +2],  texture->pixels[num + 3]));
			num+=4;
			start_draw_y++;
		}
		// num+=4;
		start_draw_x++;
		i++;
	}
}

void ft_open_texturas(t_vars *vars)
{
    vars->image = mlx_new_image(vars->mlx, 512, 512);
    vars->texture2img = mlx_new_image(vars->mlx, 512, 512);
    vars->texture = mlx_load_png("./pngwing.com.png");
    vars->texture2img = mlx_texture_to_image(vars->mlx, vars->texture);
    ft_put_texture_pix(vars, vars->texture2img, vars->texture, 0, 0);
    // mlx_image_to_window(vars->mlx,vars->texture2img, 500, 500);
    
}