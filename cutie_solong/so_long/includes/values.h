/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:08:44 by klinn             #+#    #+#             */
/*   Updated: 2024/02/15 17:35:09 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUES_H
# define VALUES_H

#define VALID_ENTITIES "ECP01"

# define OPEN_SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define KEYPRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17
# define WALL_TILE "./xpm_files/wall_grass.xpm"
# define FLOOR_TILE "./xpm_files/floor_grass.xpm"
# define PLAYER_TILE "./xpm_files/player_capy.xpm"
# define ENEMY_TILE "./xpm_files/ghost1.xpm"
# define COLLECTIBLE_TILE "./xpm_files/coin_apple.xpm"
# define EXIT_TILE "./xpm_files/exit_water.xpm"
# define TILE_SIZE 64
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307

#endif
