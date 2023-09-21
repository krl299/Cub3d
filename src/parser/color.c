/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:07 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/21 13:14:28 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_get_color(t_rgb *color, char *line)
{
	char	**tmp;
	int 	i;

	printf("get_color\n");
	i = 0;
	line += 2;
	printf("color is rgb? %d\n", color->is_rgb);
	if (color->is_rgb == 0)
	{
		tmp = ft_split(line, ',');
		while (tmp[i])
			i++;
		printf("numbers? %d\n", i);
		if (i == 3)
		{
			color->r = ft_atoi(tmp[0]);
			color->g = ft_atoi(tmp[1]);
			color->b = ft_atoi(tmp[2]);
		}
		else
			ft_error_msg(5, NULL);
		if (!ft_rgb_spectrum(color))
			ft_error_msg(5, NULL);
		else
			color->is_rgb = 1;
	}
	else
		ft_error_msg(5, NULL);
}

int	ft_rgb_spectrum(t_rgb *color)
{
	printf("get_color\n");
	if (color->r < 0 || color->r > 255)
		return (0);
	else if (color->r < 0 || color->r > 255)
		return (0);
	else if (color->r < 0 || color->r > 255)
		return (0);
	else
		return (1);
}
