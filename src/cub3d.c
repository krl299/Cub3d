/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:37:50 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/18 15:12:03 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <ctype.h>

void	ft_error_msg(int i)
{
	if (i == 0)
		ft_putstr_fd("OK.\n", 2);
	if (i == 1)
		ft_putstr_fd("Error.\n\
Wrong arguments. Must execute like: ./cub3d <'path to map file'.cub>\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error.\nFile doesn't exist.\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error.\nFile Format incorrect", 2);
	else if (i == 4)
		ft_putstr_fd("Error.\nTexture file doesn't exist.\n", 2);
	else if (i == 5)
		ft_putstr_fd("Error.\nInvalid color on file.\n", 2);
	else if (i == 6)
		ft_putstr_fd("Error.\nInvalid map.\n", 2);
	else if (i == 7)
		ft_putstr_fd("Error.\nInvalid file.\n", 2);
}

void	ft_extension_file(char *str, char **file_ext)
{
	char	*extension;
	char	*tmp;

	extension = NULL;
	tmp = ft_strchr(str, '/');
	while (tmp != NULL)
	{
		extension = ++tmp;
		tmp  = ft_strchr(tmp, '/');
	}
	extension  = ft_strchr(extension, '.');
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

void	ft_init_info(t_file_info *info)
{
	info->fd = 0;
	info->file_path = NULL;
	info->file_extension = NULL;
	info->no_texture = NULL;
	info->no_extension = NULL;
	info->so_texture = NULL;
	info->so_extension = NULL;
	info->we_texture = NULL;
	info->we_extension = NULL;
	info->ea_texture = NULL;
	info->ea_extension = NULL;
	info->floor_color = NULL;
	info->ceiling_color = NULL;
	info->map = NULL;
}

void	ft_get_textures(t_file_info *info)
{
//	search for texture of walls starting by NO, SO, WE, EA
//	check if can open texture and extension in case that can open it
//	check if color is on rgb spectrum (0,255)
//	get the map with spaces

	char	*line;
	int		fd;

	line = get_next_line(info->fd);
	while (line != NULL)
	{
		while (isspace(*line) == 1)
			line++;
		if (ft_strncmp(line, "NO ", 3) == 0)
		{
			line += 3;
			while (isspace(*line) == 1)
				line++;
			info->no_texture = ft_strtrim(line, " \n");
			fd = open(info->no_texture, O_RDONLY);
			if (fd == -1)
				ft_error_msg(4);
			else
				close(fd);
			ft_extension_file(info->no_texture, &info->no_extension);
		}
		line = get_next_line(info->fd);
	}
}

void	ft_check_arg(char *str, t_file_info *info)
{
	int	fd;
//	check if has the correct extension "*.cub"
//	check if can open it
//	check format of file

	ft_extension_file(str, &info->file_extension);
	if (info->file_extension != NULL && ft_strncmp(info->file_extension, "cub", 3) == 0)
	{
			fd = open(str, O_RDONLY);
			if (fd == -1)
				ft_error_msg(2);
			info->fd = fd;
			info->file_path = ft_strdup(str);
			ft_get_textures(info);
	}
	else
		ft_error_msg(7);
}

void	ft_print_info(t_file_info *info)
{
	printf("<----	INFO	---->\n");
	printf("fd : %d\n", info->fd);	
	printf("file_path : %s\n", info->file_path);
	printf("file_extension : %s\n", info->file_extension);
	printf("no_texture : %s\n", info->no_texture);
	printf("no_extension : %s\n", info->no_extension);
	printf("so_texture : %s\n", info->so_texture);
	printf("so_extension : %s\n", info->so_extension);
	printf("we_texture : %s\n", info->we_texture);
	printf("we_extension : %s\n", info->we_extension);
	printf("ea_texture : %s\n", info->ea_texture);
	printf("ea_extension : %s\n", info->ea_extension);
//	printf("floor rgb : (%d, %d, %d)", info->floor_color->r, info->floor_color->g, info->floor_color->b);
//	printf("ceiling rgb : (%d, %d, %d)", info->floor_color->r, info->floor_color->g, info->floor_color->b);
	//map
//	ft_print_map(info->map);
}

int	main(int argc, char *argv[])
{
	t_file_info	info;

	if (argc == 2)
	{
		ft_init_info(&info);
		ft_check_arg(argv[1], &info);
		ft_print_info(&info);
	}
	else
	{
		ft_error_msg(1);
	}
	return (0);
}
