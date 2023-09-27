/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:39:19 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/27 12:31:39 by cmoran-l         ###   ########.fr       */
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
	int	is_rgb;
}	t_rgb;

typedef struct s_file_info
{
	int		elements;
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
	t_rgb	floor_color;
	t_rgb	ceiling_color;
	char	**map;
	int		map_size;
	int		players;
}	t_file_info;

//	Init.c
void	ft_init_info(t_file_info *info);
void	ft_clean_info(t_file_info *info);
void	ft_init_rgb(t_rgb *rgb);
void	ft_init_map(t_file_info *info, int size, char **cpy);

//	Parser.c	
void	ft_check_arg(char *str, t_file_info *info);
void	ft_extension_file(char *str, char **file_ext);
void	ft_get_info(t_file_info *info);

//	Textures.c
void	ft_get_no_texture(t_file_info *info,char *line);
void	ft_get_so_texture(t_file_info *info,char *line);
void	ft_get_we_texture(t_file_info *info,char *line);
void	ft_get_ea_texture(t_file_info *info,char *line);
void	ft_check_textures(t_file_info * info);

//	Color.c
void	ft_get_color(t_rgb *color, char *line);
int		ft_rgb_spectrum(t_rgb *color);

//	Map.c
void	ft_get_map(t_file_info *info, char *line);
int		ft_hasplayer(t_file_info *info);
void	ft_checkwalls(t_file_info *info);

//	Error functions
void	ft_error_msg(int i, t_file_info *info);

//	Funtions to add on libft
int		ft_isspace(int c);
void	ft_clean_doublepointer(char **tmp, int size);
void	ft_replace(char *str, const char search, const char replace);

//	Test funtions
void	ft_print_info(t_file_info *info);
void	ft_print_map(t_file_info *info);

#endif
