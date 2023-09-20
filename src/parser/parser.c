/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:33:43 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/20 13:10:02 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_extension_file(char *str, char **file_ext)
{
	char	*extension;
	char	*tmp;

	extension = NULL;
	tmp = ft_strchr(str, '/');
	while (tmp != NULL)
	{
		extension = ++tmp;
		tmp = ft_strchr(tmp, '/');
	}
	extension = ft_strchr(extension, '.');
	if (extension != NULL)
	{
	extension[ft_strlen(extension)] = 0;
		if (ft_strncmp(extension, ".cub\0", 5) == 0)
			*file_ext = ft_strdup("cub");
		else if (ft_strncmp(extension, ".png\0", 5) == 0)
			*file_ext = ft_strdup("png");
		else if (ft_strncmp(extension, ".xmp42\0", 7) == 0)
			*file_ext = ft_strdup("xmp42");
		else
			*file_ext = NULL;
	}
	else
		*file_ext = NULL;
}

void	ft_get_color(t_rgb *color, char *line)
{
	int		i;
	int		j;
	char	**rgb;

	i = 0;
	j = 0;
	rgb = ft_split(line, ',');
	while (rgb[i] != NULL)
		i++;
	if (i == 2)
	{
		color->r = ft_atoi(rgb[0]);
		color->g = ft_atoi(rgb[1]);
		color->b = ft_atoi(rgb[2]);
	}
	else
		ft_error_msg(8, NULL);
	while (rgb[j] != NULL)
		free(rgb[j++]);
	free(rgb);
}

void	ft_get_colors(t_file_info *info)
{
	char	*line;
	char	*tmp;

	line = get_next_line(info->fd);
	printf("line : %s\n", line);
	while (line != NULL || (info->floor_color == NULL && info->ceiling_color == NULL))
	{
		tmp = line;
		while (ft_isspace(*line) == 1)
			line++;
		if (ft_strncmp(line, "F ", 2) == 0)
			ft_get_color(info->floor_color, line);
		else if (ft_strncmp(line, "C ", 2) == 0)
			ft_get_color(info->ceiling_color, line);
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
		ft_get_textures(info);
		ft_print_info(info);
		//ft_get_colors(info);
	}
	else
		ft_error_msg(7, info);
}
