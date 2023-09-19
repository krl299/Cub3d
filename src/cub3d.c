/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:37:50 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/09/19 12:13:48 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
c == '\f' || c == 'r' || c == ' ')
		return (1);
	else
		return (0);
}

void	ft_leaks(void)
{
	system("leaks -q cub3d");
}

int	main(int argc, char *argv[])
{
	t_file_info	info;

	atexit(ft_leaks);
	if (argc == 2)
	{
		ft_init_info(&info);
		ft_check_arg(argv[1], &info);
		ft_print_info(&info);
	}
	else
	{
		ft_error_msg(1, &info);
	}
	return (0);
}
