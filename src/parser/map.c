/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:39:18 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/11/11 12:08:01 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_get_map(t_file_info *info, char *line)
{
	char	*ptr[20000];
	int		i;
//printf("get_map\n");
	i = 0;
	if (ft_strchr(line, '1') != NULL)
	{
		while (line != NULL && i < 200)
		{
			if (*line == '\n')
			{
				ft_error_msg(6, NULL);
				return ;
			}
			ptr[i] = ft_substr(line, 0, ft_strlen(line));
			ft_replace(ptr[i], ' ', '1');
			free(line);
			line = get_next_line(info->fd);
			i++;
		}
		ft_init_map(info, i, ptr);
		if (ft_hasplayer(info))
			ft_checkwalls(info);
		ft_clean_doublepointer(ptr, i);
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
	if (info->players != 1)
	{
		ft_error_msg(6, NULL);
		return (0);
	}
	else
		return (1);
}

static void	ft_endline_map(t_file_info *info, int diff, int i)
{
	if (i >= 1)
	{
		diff = ft_strlen(info->map[i - 1]) - \
				ft_strlen(info->map[i]);
		if (diff < 0)
		{
			while (diff != 0)
			{
				if (info->map[i][ft_strlen(info->map[i]) + diff - 1] == '1')
					diff++;
				else
					ft_error_msg(6, NULL);
			}
		}
		else if (diff > 0)
		{
			while (diff != 0)
			{
				if (info->map[i - 1][ft_strlen(info->map[i]) + diff - 1] == '1')
					diff--;
				else
					ft_error_msg(6, NULL);
			}
		}
	}
}

//too long
void	ft_checkwalls(t_file_info *info)
{
	int	i;

	i = -1;
	while (info->map[0][++i])
	{
		if (info->map[0][i] != '1')
		{
			ft_error_msg(6, NULL);
			return ;
		}
	}
	i = 0;
	while (info->map[++i] && i < info->map_size - 1)
	{
		if (info->map[i][0] != '1' || info->map[i][ft_strlen(info->map[i]) - 1] != '1')
		{
			ft_error_msg(6, NULL);
			return ;
		}
		ft_endline_map(info, 0, i);
	}
	i = -1;
	while (info->map[info->map_size -1][++i])
		if (info->map[info->map_size - 1][i] != '1')
			ft_error_msg(6, NULL);
}
