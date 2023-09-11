/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:04:39 by mandriic          #+#    #+#             */
/*   Updated: 2022/01/11 19:04:46 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include "./libft/libft.h"
# include "./libft/gnl/get_next_line.h"


#define WIDTH 2048
#define HEIGHT 1024
#define KOEF_X 10
#define SPEEX 5
#define SPEEY 5



typedef struct var_idnf
{
	mlx_t* 	mlx;
	mlx_image_t* image;
	mlx_image_t* sky;
	mlx_image_t* gun;
	mlx_texture_t *gun_text;
	mlx_texture_t* texture;
	mlx_image_t* texture2img;
	mlx_image_t* texture3img;
	mlx_image_t* for_texture_print;
	xpm_t* xpm;
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
}t_vars;


#endif
