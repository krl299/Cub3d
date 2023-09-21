/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:49:06 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/21 12:49:00 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//	Different textures for each wall
void	ft_check_textures(t_file_info *info)
{
	if (info->no_texture != NULL && info->so_texture != NULL && \
		info->we_texture != NULL && info->ea_texture != NULL && \
		ft_strncmp(info->no_texture, info->so_texture, ft_strlen(info->no_texture)) != 0 && \
		ft_strncmp(info->no_texture, info->we_texture, ft_strlen(info->no_texture)) != 0 && \
		ft_strncmp(info->no_texture, info->ea_texture, ft_strlen(info->no_texture)) != 0 && \
		ft_strncmp(info->so_texture, info->we_texture, ft_strlen(info->so_texture)) != 0 && \
		ft_strncmp(info->so_texture, info->ea_texture, ft_strlen(info->so_texture)) != 0 && \
		ft_strncmp(info->we_texture, info->ea_texture, ft_strlen(info->we_texture)) != 0)
		return ;
	else
		ft_error_msg(9, info);
}

void	ft_get_no_texture(t_file_info *info, char *line)
{	
	int	fd;

	printf("no_texture\n");
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
		info->elements++;
	}
	else
		ft_error_msg(8, info);
}

void	ft_get_so_texture(t_file_info *info, char *line)
{	
	int	fd;

	printf("so_texture\n");
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
		info->elements++;
	}
	else
		ft_error_msg(8, info);
}

void	ft_get_we_texture(t_file_info *info, char *line)
{	
	int	fd;

	printf("we_texture\n");
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
		info->elements++;
	}
	else
		ft_error_msg(8, info);
}

void	ft_get_ea_texture(t_file_info *info, char *line)
{	
	int	fd;

	printf("ea_texture\n");
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
		info->elements++;
	}
	else
		ft_error_msg(8, info);
}
