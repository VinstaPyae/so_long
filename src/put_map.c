/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:50:13 by pzaw              #+#    #+#             */
/*   Updated: 2024/10/17 18:00:29 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_mpp *mp_info)
{
	mp_info->collectibles = 0;
	mp_info->player = 0;
	mp_info->exit = 0;
	mp_info->walls = 0;
	mp_info->path = 0;
	mp_info->width = 0;
	mp_info->height = 0;
	mp_info->fd_mp = -1;
}

int	file_validation(t_mpp *mp_info, char **av)
{
	char *file_ext;

	file_ext = ft_strrchr(av[1], '.');
	if (!file_ext || ft_strncmp(file_ext, ".ber", 5))
	{
		printf("map incorrect\n");
		return (0);
	}
	mp_info->fd_mp = open(av[1], O_RDONLY);
	if (mp_info->fd_mp < 0)
	{
		close(mp_info->fd_mp);
		fd_error();
	}
	return (1);
}

void	put_map(t_mpp *mp_info, char **argv)
{
	int	byt_rd;
	int	i;
	
	i = -1;
	init_map(mp_info);
	if (!file_validation(mp_info, argv))
			return ;
	byt_rd = read(mp_info->fd_mp, mp_info->buff, BUFFER_SIZE);
	if (byt_rd < 0)
	{
		free(mp_info->buff);
		close(mp_info->fd_mp);
		fd_error();
	}
	mp_info->map_file = ft_split(mp_info->buff, '\n');
	if (!mp_info->map_file)
		ft_free_mem(mp_info->map_file);
	close(mp_info->fd_mp);
}
