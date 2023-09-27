/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:39:18 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/27 13:48:31 by cmoran-l         ###   ########.fr       */
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
		i = 0;
		while (i < info->map_size && info->map[i])
		{
			ft_replace(info->map[i], ' ', '1');
			i++;
		}
		printf("numbers of players: %d\n", ft_hasplayer(info));
		ft_checkwalls(info);
//		ft_clean_doublepointer(ptr, i);
//		free(line);
	}
}

void	ft_replace(char *str, const char search, const char replace)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (i < (int)ft_strlen(str) && str[i])
		{
			if (str[i] == search)
				str[i] = replace;
			i++;
		}
	}
	return ;
}

int	ft_hasplayer(t_file_info *info)
{
	int	i;

	i = 0;
	while (i < info->map_size && info->map[i])
	{
		if (ft_strchr(info->map[i], 'N') != 0 || \
			ft_strchr(info->map[i], 'E') != 0 || \
			ft_strchr(info->map[i], 'S') != 0 || \
			ft_strchr(info->map[i], 'W') != 0)
			info->players++;
		i++;
	}
	//error msg to say hasn't 1 player on map
	if (info->players != 1)
		return (0);
	else
		return (1);
}

void	ft_checkwalls(t_file_info *info)
{
	printf("check walls\n");
	// check first and last row are filled by 1s
	// check first and last char each row is 1
	// check the length row-1 and row+1 that are 1 on each line
	int	i;

	i = -1;
	while (info->map[0][++i])
		if (info->map[0][i] != '1')
		{
			printf("primera linea de mapa no esta cerrada por completo\n");
			return ;
		}
	i = 0;
	while (info->map[++i] && i < info->map_size - 1)
	{
		if (info->map[i][0] != '1' || info->map[i][ft_strlen(info->map[i]) - 1] != '1')
		{
			printf("mapa invalido\n");
			return ;
		}
		if (i >= 1)
		{
			int diff = ft_strlen(info->map[i - 1]) - ft_strlen(info->map[i]);
			printf("diff = %d\n", diff);
			if (diff < 0)
			{
				while (diff != 0)
				{
					if (info->map[i][ft_strlen(info->map[i]) + diff - 1] == '1')
						diff++;
					else
					{
						printf("invalid map\n");
						return ;
					}
				}
			}
			else if (diff > 0)
			{
				while (diff != 0)
				{
					if (info->map[i - 1][ft_strlen(info->map[i]) + diff - 1] == '1')
						diff--;
					else
					{
						printf("invalid map\n");
						return ;
					}
				}
			}
		}
	}
	i = -1;
	while (info->map[info->map_size -1][++i])
		if (info->map[info->map_size - 1][i] != '1')
		{
			printf("ultima linea de mapa no esta cerrada por completo\n");
			return ;
		}

	printf("el mapa esta correcto.\n");
}
