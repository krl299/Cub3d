/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:49:06 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/19 12:56:46 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_get_textures(t_file_info *info)
{
	char	*line;
	char	*tmp;

	line = get_next_line(info->fd);
	while (line != NULL)
	{
		tmp = line;
		while (ft_isspace(*line) == 1)
			line++;
		if (ft_strncmp(line, "NO ", 3) == 0)
			ft_get_no_texture(info, line);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			ft_get_so_texture(info, line);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			ft_get_we_texture(info, line);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			ft_get_ea_texture(info, line);
		free(tmp);
		line = get_next_line(info->fd);
	}
}

void	ft_get_no_texture(t_file_info *info, char *line)
{	
	int	fd;

	if (info->no_texture == NULL)
	{
		line += 3;
		while (ft_isspace(*line) == 1)
			line++;
		info->no_texture = ft_strtrim(line, " \n");
		fd = open(info->no_texture, O_RDONLY);
		if (fd == -1)
			ft_error_msg(4, info);
		else
			close(fd);
		ft_extension_file(info->no_texture, &info->no_extension);
	}
	else
		ft_error_msg(8, info);
}

void	ft_get_so_texture(t_file_info *info, char *line)
{	
	int	fd;

	if (info->so_texture == NULL)
	{
		line += 3;
		while (ft_isspace(*line) == 1)
			line++;
		info->so_texture = ft_strtrim(line, " \n");
		fd = open(info->so_texture, O_RDONLY);
		if (fd == -1)
			ft_error_msg(4, info);
		else
			close(fd);
		ft_extension_file(info->so_texture, &info->so_extension);
	}
	else
		ft_error_msg(8, info);
}

void	ft_get_we_texture(t_file_info *info, char *line)
{	
	int	fd;

	if (info->we_texture == NULL)
	{
		line += 3;
		while (ft_isspace(*line) == 1)
			line++;
		info->we_texture = ft_strtrim(line, " \n");
		fd = open(info->we_texture, O_RDONLY);
		if (fd == -1)
			ft_error_msg(4, info);
		else
			close(fd);
		ft_extension_file(info->we_texture, &info->we_extension);
	}
	else
		ft_error_msg(8, info);
}

void	ft_get_ea_texture(t_file_info *info, char *line)
{	
	int	fd;

	if (info->ea_texture == NULL)
	{
		line += 3;
		while (ft_isspace(*line) == 1)
			line++;
		info->ea_texture = ft_strtrim(line, " \n");
		fd = open(info->ea_texture, O_RDONLY);
		if (fd == -1)
			ft_error_msg(4, info);
		else
			close(fd);
		ft_extension_file(info->ea_texture, &info->ea_extension);
	}
	else
		ft_error_msg(8, info);
}
