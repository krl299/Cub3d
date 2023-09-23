/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:39:19 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/12 10:48:47 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "../libraries/libft/libft.h"

#define WIDTH 2048
#define HEIGHT 1024
#define KOEF 64
#define SPEEX 1
#define SPEEY 5

typedef struct var_map
{
	char **map_matrix;
	
}t_map;

typedef struct var_idnf
{
	mlx_t* 	mlx;
	mlx_image_t* image;
	mlx_image_t* sky;
	mlx_image_t* wall;
	mlx_image_t* mini_map;
	mlx_image_t* mini_unit;
	mlx_image_t* gun;
	mlx_texture_t *gun_text;
	mlx_texture_t* texture;
	mlx_image_t* texture2img;
	mlx_image_t* texture3img;
	mlx_image_t* for_texture_print;
	xpm_t* xpm;
	float mini_u_angle;
	int start_draw_y_mm;
	int put_unit_x;
	int put_unit_y;
	int len_char;
	int mini_unit_xy[2];
	int len_mm[2];
	int cam[2];
	int 	cont_x_right;
	int 	cont_x_left;
	int 	cont_y_up;
	int 	cont_y_down;
	int 	cont_y;
	int 	cont_x;
	int		size_x;
	int		size_y;
	int		new_size_h;
	int		new_size_w;
	int		save_pos_x;
	int		save_pos_y;
	void	*wind;
	char	**map;
	int		lenmap;
	int		start_draw_x;
	int		start_draw_y;
	int		heightmap;
	int		step;
	int		check;
	t_map	*map_mtr;
}t_vars;



int ft_get_rgba(int r, int g, int b, int a);
void ft_create_sky(t_vars *vars, mlx_image_t *img, int size, int size2, unsigned int col);
void ft_hook(void* param);
void ft_trace_line(t_vars *vars);

# endif