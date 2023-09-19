/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:19:24 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/19 12:22:59 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_error_msg(int i, t_file_info *info)
{
	(void)info;
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
	else if (i == 8)
		ft_putstr_fd("Error.\nMore textures for the same orientation.\n", 2);
//	ft_clean_info(info);
}
