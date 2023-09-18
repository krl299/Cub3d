/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:39:19 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/18 15:42:35 by cmoran-l         ###   ########.fr       */
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

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_file_info
{
	int		fd;
	char	*file_path;
	char	*file_extension;
	char	*no_texture;
	char	*no_extension;
	char	*so_texture;
	char	*so_extension;
	char	*we_texture;
	char	*we_extension;
	char	*ea_texture;
	char	*ea_extension;
	t_rgb	*floor_color;
	t_rgb	*ceiling_color;
	char	**map;
}	t_file_info;

//	Parser.c	
void	ft_check_arg(char *str, t_file_info *info);
void	ft_extension_file(char *str, char **file_ext);
void	ft_get_textures(t_file_info *info);

//	Error functions
void	ft_error_msg(int i);

//	Funtions to add on libft
int		ft_isspace(int c);

#endif
