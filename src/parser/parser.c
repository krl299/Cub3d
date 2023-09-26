/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:33:43 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/26 12:06:11 by cmoran-l         ###   ########.fr       */
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

void	ft_get_info(t_file_info *info)
{
	char	*line;
	char	*tmp;

	printf("get_info\n");
	line = get_next_line(info->fd);
	while (line != NULL)
	{
		tmp = line;
		printf("%s", tmp);
		printf("elements : %d\n", info->elements);
		while (ft_isspace(*line) == 1)
			line++;
		printf("line : %s", line);
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
		else if (info->elements == 6 && !(*tmp == '\n'))
		{
			ft_check_textures(info);
			printf("\n");
			ft_get_map(info, tmp);
			printf("end get function\n");
			break;
		}
		else if (!(*tmp == '\n'))
			ft_error_msg(3, info);
		free(tmp);
		line = get_next_line(info->fd);
	}
	//free(line);
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

	printf("inside check\n");
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
