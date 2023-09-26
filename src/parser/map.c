/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:39:18 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/26 13:53:03 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_get_map(t_file_info *info, char *line)
{
	char	*ptr[200];
	int		i;

	i = 0;
	printf("get_map\n");
	if (ft_strchr(line, '1') != NULL)
	{
		while (line != NULL && i < 200)
		{
			if (*line == '\n')
			{
				// do a msg for this case
				ft_error_msg(0, NULL);
				return ;
			}
			ptr[i] = ft_substr(line, 0, ft_strlen(line));
			//printf("map: %s\n", ptr[i]);
			free(line);
			line = get_next_line(info->fd);
			i++;
		}
		printf("columns map: %i\n", i);
		ft_init_map(info, i, ptr);
//		ft_spacetozero(info);
//		ft_hasplayer(info);
	//	ft_clean_doublepointer(ptr, i);
//		free(line);
	}
}
