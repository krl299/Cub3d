/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:37:50 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/14 13:35:17 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

	extension  = ft_strchr(str, '.');
	if (extension != NULL)
	{
		if (ft_strncmp(extension, ".cub", 4) == 0 && \
			(ft_strlen(extension) == ft_strlen(".cub")))
		{
			*file_ext = ft_strdup("cub");
			ft_putstr_fd("Extension file .cub\n", 1);
		}
		else if (ft_strncmp(extension, ".png", 4) == 0 && \
				(ft_strlen(extension) == ft_strlen(".png")))
		{
			*file_ext = ft_strdup("png");
			ft_putstr_fd("Extension file .png\n", 1);
		}
		else if (ft_strncmp(extension, ".xmp42", 6) == 0 && \
				(ft_strlen(extension) == ft_strlen(".xmp42")))
		{
			*file_ext = ft_strdup("xmp42");
			ft_putstr_fd("Extension file .xmp42\n", 1);
		}
		else
		{
			*file_ext = NULL;
			ft_putstr_fd("No extension\n", 1);
			//ft_clean_exit();
		}
	}
}

void	ft_check_arg(char *str, t_file_info *info)
{
	int	fd;
//	check if has the correct extension "*.cub"
//	check if can open it
//	check format of file
//	check if can open texture and extension in case that can open it
//	check if color is on rgb spectrum (0,255)

	ft_extension_file(str, &info->file_extension);
	if (info->file_extension != NULL)
	{
		if (ft_strncmp(info->file_extension, "cub", 3) == 0)
		{
			fd = open(str, O_RDONLY);
			if (fd == -1)
				ft_error_msg(2);
			info->fd = fd;
			info->file_path = ft_strdup(str);
		}
		else
			ft_error_msg(7);
	}
}

void	ft_print_info(t_file_info *info)
{
	printf("<----	INFO	---->\n");
	printf("fd : %d\n", info->fd);	
	printf("file_path : %s\n", info->file_path);
	printf("file_extension : %s\n", info->file_extension);
	printf("no_texture : %s\n", info->no_texture);
	printf("no_extension : %s\n", info->no_texture);
	printf("so_texture : %s\n", info->so_texture);
	printf("so_extension : %s\n", info->so_texture);
	printf("we_texture : %s\n", info->we_texture);
	printf("we_extension : %s\n", info->we_texture);
	printf("ea_texture : %s\n", info->ea_texture);
	printf("ea_extension : %s\n", info->ea_texture);
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
		ft_check_arg(argv[1], &info);
		ft_print_info(&info);
	}
	else
	{
		ft_error_msg(1);
	}
	return (0);
}
