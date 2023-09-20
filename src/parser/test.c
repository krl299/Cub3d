/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:20:06 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/20 13:08:19 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
//	printf("floor_color : (%d, %d, %d)\n", info->floor_color->r, info->floor_color->g, info->floor_color->b);
//	printf("ceiling_color : (%d, %d, %d)\n", info->ceiling_color->r, info->ceiling_color->g, info->ceiling_color->b);
//	printf("map :\n");
//	ft_print_map(info->map);
}
