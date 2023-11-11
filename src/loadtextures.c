/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadtextures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:50:17 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/11/11 12:08:58 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//load textures of walls
//TODO clean exit in error case
void ft_loadtextures(t_file_info *info, t_vars *vars)
{
    vars->no_wall_texture = mlx_load_png(info->no_texture);
    if (!vars->no_wall_texture)
        exit(2);
    //printf("no_texture loaded\n");
    vars->so_wall_texture = mlx_load_png(info->so_texture);
    if (!vars->so_wall_texture)
        exit(2);
    //printf("so_texture loaded\n");
    vars->we_wall_texture = mlx_load_png(info->we_texture);
    if (!vars->we_wall_texture)
        exit(2);
    //printf("we_texture loaded\n");
    vars->ea_wall_texture = mlx_load_png(info->ea_texture);
    if (!vars->ea_wall_texture)
        exit(2);
    //printf("ea_texture loaded\n");
}