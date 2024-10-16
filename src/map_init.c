/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:50:13 by pzaw              #+#    #+#             */
/*   Updated: 2024/10/16 21:36:24 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_mpp *mp_info)
{
	int	byt_rd;
	int	i;
	
	i = -1;
	byt_rd = read(mp_info->fd_mp, mp_info->buff, BUFFER_SIZE);
	if (byt_rd < 0)
	{
		free(mp_info->buff);
		close(mp_info->fd_mp);
		ft_error();
	}
	mp_info->map = ft_split(mp_info->buff, '\n');
	while (mp_info->map[++i])
	{
		printf("%s\n", mp_info->map[i]);
	}
	close(mp_info->fd_mp);
}
