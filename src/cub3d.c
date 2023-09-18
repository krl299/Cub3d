/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:37:50 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/18 16:12:00 by cmoran-l         ###   ########.fr       */
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

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == 'r' || c == ' ')
		return (1);
	else
		return (0);
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
