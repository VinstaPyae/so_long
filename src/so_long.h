/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:28:18 by pzaw              #+#    #+#             */
/*   Updated: 2024/10/17 16:58:31 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_mpp
{
	char	**map_file;
	char	buff[BUFFER_SIZE + 1];
	int		fd_mp;
	int		width;
	int		height;
	int		collectibles;
	int		player;
	int		walls;
	int		exit;
	int		path;
}		t_mpp;

void	put_map(t_mpp *mp_info, char **argv);
void	fd_error(void);
void	ft_free_mem(char **tab);

#endif