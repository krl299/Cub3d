/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:33:43 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/10/12 13:02:59 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_get_extension(char *extension, char **file_ext)
{
	if (ft_strncmp(extension, ".cub\0", 5) == 0)
		*file_ext = ft_strdup("cub");
	else if (ft_strncmp(extension, ".png\0", 5) == 0)
		*file_ext = ft_strdup("png");
	else if (ft_strncmp(extension, ".xmp42\0", 7) == 0)
		*file_ext = ft_strdup("xmp42");
	else
		*file_ext = NULL;
}

void	ft_extension_file(char *str, char **file_ext)
{
	char	*extension;
	char	*tmp;

	extension = NULL;
	tmp = ft_strchr(str, '/');
	if (tmp == NULL)
		return ;
	while (tmp != NULL)
	{
		extension = ++tmp;
		tmp = ft_strchr(tmp, '/');
	}
	extension = ft_strchr(extension, '.');
	if (extension != NULL)
	{
		extension[ft_strlen(extension)] = 0;
		ft_get_extension(extension, file_ext);
	}
	else
		*file_ext = NULL;
}

static int	ft_identify_textures_colors(char *line, t_file_info *info)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		ft_get_no_texture(info, line);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		ft_get_so_texture(info, line);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		ft_get_we_texture(info, line);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		ft_get_ea_texture(info, line);
	else if (ft_strncmp(line, "F ", 2) == 0)
	{
		ft_get_color(&info->floor_color, line);
		info->elements++;
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		ft_get_color(&info->ceiling_color, line);
		info->elements++;
	}
	else
		return (0);
	return (1);
}

void	ft_get_info(t_file_info *info)
{
	char	*line;
	char	*tmp;

	line = get_next_line(info->fd);
	while (line != NULL)
	{
		tmp = line;
		while (ft_isspace(*line) == 1)
			line++;
		if (!ft_identify_textures_colors(line, info))
		{
			if (info->elements == 6 && !(*tmp == '\n'))
			{
				ft_check_textures(info);
				ft_get_map(info, tmp);
				break ;
			}
			else if (!(*tmp == '\n'))
				ft_error_msg(3, info);
		}
		free(tmp);
		line = get_next_line(info->fd);
	}
}

//	check if has the correct extension "*.cub"
//	check if can open it
//	check format of file
//	search for texture of walls starting by NO, SO, WE, EA
//	check if can open texture and extension in case that can open it
//	check if there are more than one texture
//	check if color is on rgb spectrum (0,255)
//	get the map with spaces
//	has only 1 player
//	has surrounded by walls
void	ft_check_arg(char *str, t_file_info *info)
{
	int	fd;

	ft_extension_file(str, &info->file_extension);
	if (info->file_extension != NULL && \
ft_strncmp(info->file_extension, "cub", 3) == 0)
	{
		fd = open(str, O_RDONLY);
		if (fd == -1)
			ft_error_msg(2, info);
		info->fd = fd;
		info->file_path = ft_strdup(str);
		ft_get_info(info);
	}
	else
		ft_error_msg(7, info);
}
