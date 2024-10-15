/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:13:57 by pzaw              #+#    #+#             */
/*   Updated: 2024/10/15 21:37:08 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(int ac, char **av, t_mpp *mp_info)
{
	mp_info->ac = ac;
	mp_info->av = av;
	mp_info->fd_mp = open(mp_info->av[1], O_RDONLY);
}

void	ft_error(void)
{
	perror("\033[1;31m🛑ERROR:\033[0m");
	exit(1);
}

int	file_validation(t_mpp *mp_info)
{
	char *file_ext;

	file_ext = ft_strrchr(mp_info->av[1], '.');
	if (!file_ext || ft_strncmp(file_ext, ".ber", 5))
	{
		ft_error();
	}
	else
	{
		if (mp_info->fd_mp < 0)
			ft_error();
	}
	return (mp_info->fd_mp);
}

int	main(int argc, char **argv)
{
	t_mpp mp_info;

	if (argc == 2)
	{
		init(argc, argv, &mp_info);
		file_validation(&mp_info);
	}
	else
		ft_putstr_fd("\033[1;31m🛑Error:\033[0m No Map\n", 1);
}