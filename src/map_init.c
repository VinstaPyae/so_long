/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:50:13 by pzaw              #+#    #+#             */
/*   Updated: 2024/10/16 19:00:16 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_mpp *mp_info)
{
	char	*tmp;
	int	byt_rd;
	
	mp_info->mp_file = ft_calloc(1,1);
	if (mp_info->mp_file == 0)
	{
		close(mp_info->fd_mp);
		ft_error();
	}
	byt_rd = read(mp_info->fd_mp, mp_info->buff, BUFFER_SIZE);
	while (byt_rd > 0)
	{
		mp_info->buff[byt_rd] = '\0';
		tmp = ft_calloc(ft_strlen(mp_info->mp_file) + byt_rd + 1, 1);
		if (tmp == NULL)
		{
			free(mp_info->mp_file);
			close(mp_info->fd_mp);
			ft_error();
		}
		ft_strlcpy(tmp, mp_info->mp_file, ft_strlen(mp_info->mp_file));
		ft_strlcat(tmp, mp_info->buff, ft_strlen(mp_info->buff));
		free(mp_info->mp_file);
		mp_info->mp_file = tmp;
	}
	if (byt_rd < 0)
	{
		free(mp_info->mp_file);
		close(mp_info->fd_mp);
		ft_error();
	}
	close(mp_info->fd_mp);
}
