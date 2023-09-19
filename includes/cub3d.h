/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:39:19 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/19 12:10:55 by cmoran-l         ###   ########.fr       */
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

//	Init.c
void	ft_init_info(t_file_info *info);
void	ft_clean_info(t_file_info *info);

//	Parser.c	
void	ft_check_arg(char *str, t_file_info *info);
void	ft_extension_file(char *str, char **file_ext);
void	ft_get_textures(t_file_info *info);

//	Textures.c
void	ft_get_no_texture(t_file_info *info,char *line);
void	ft_get_so_texture(t_file_info *info,char *line);
void	ft_get_we_texture(t_file_info *info,char *line);
void	ft_get_ea_texture(t_file_info *info,char *line);


//	Error functions
void	ft_error_msg(int i, t_file_info *info);

//	Funtions to add on libft
int		ft_isspace(int c);

//	Test funtions
void	ft_print_info(t_file_info *info);

#endif
