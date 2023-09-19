/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:06:26 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/19 12:22:08 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	ft_clean_info(t_file_info *info)
{
	if (info->file_path != NULL)
		free(info->file_path);
	if (info->file_extension !=  NULL)	
		free(info->file_extension);
	if (info->no_texture != NULL)
		free(info->no_texture);
	if (info->no_extension != NULL)
		free(info->no_extension);
	if (info->so_texture != NULL)
		free(info->so_texture);
	if (info->so_extension != NULL)
		free(info->so_extension);
	if (info->we_texture != NULL)
		free(info->we_texture);
	if (info->we_extension != NULL)
		free(info->we_extension);
	if (info->ea_texture != NULL)
		free(info->ea_texture);
	if (info->ea_extension != NULL)
		free(info->ea_extension);
}
