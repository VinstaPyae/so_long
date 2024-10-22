/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:13:34 by pzaw              #+#    #+#             */
/*   Updated: 2024/10/17 18:28:17 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fd_error(void)
{
	perror("\033[1;31m🛑ERROR:\033[0m");
	exit(1);
}

void	ft_error_map(t_mpp *mp_info)
{
	ft_free_mem(mp_info->map_file);
	free(mp_info->buff);
	ft_putendl_fd("Error: Invalid map elements\n", 1);
	exit(1);
}

void	ft_free_mem(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}