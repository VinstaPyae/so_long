/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:13:57 by pzaw              #+#    #+#             */
/*   Updated: 2024/10/16 19:44:09 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	perror("\033[1;31m🛑ERROR:\033[0m");
	exit(1);
}

void	file_validation(t_mpp *mp_info, char **av)
{
	char *file_ext;

	file_ext = ft_strrchr(av[1], '.');
	if (!file_ext || ft_strncmp(file_ext, ".ber", 5))
	{
		printf("map incorrect");
		ft_error();
	}
	mp_info->fd_mp = open(mp_info->av[1], O_RDONLY);
	if (mp_info->fd_mp < 0)
	{
		printf("map incorrect %d", mp_info->fd_mp);
		ft_error();
	}
	map_init(mp_info);
}

int	main(int argc, char **argv)
{
	t_mpp mp_info;

	if (argc == 2)
	{
		file_validation(&mp_info, argv);
		
	}
	else
		ft_putstr_fd("\033[1;31m🛑Error:\033[0mNO MAP\n", 1);
}