/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:33:43 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/19 12:56:51 by cmoran-l         ###   ########.fr       */
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

//	check if has the correct extension "*.cub"
//	check if can open it
//	check format of file
//	search for texture of walls starting by NO, SO, WE, EA
//	check if can open texture and extension in case that can open it
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
	}
	else
		ft_error_msg(7, info);
}
