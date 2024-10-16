/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:28:18 by pzaw              #+#    #+#             */
/*   Updated: 2024/10/16 19:03:50 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_mpp
{
	char	*mp_file;
	char	buff[BUFFER_SIZE + 1];
	char	**av;
	int		ac;
	int		fd_mp;
}		t_mpp;

void	map_init(t_mpp *mp_info);
void	ft_error(void);

#endif