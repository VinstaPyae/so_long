/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:07:45 by klinn             #+#    #+#             */
/*   Updated: 2024/02/15 17:34:45 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define MALLOC_ERR "malloc() failed\n"
# define MLX_INIT_ERR "Failed to initialize mlx\n"
# define MLX_NEW_WINDOW_ERR "Failed to open a new window\n"
# define WIN_MSG "\n\t<<< Congratulation!! You Won !! >>>\n"
# define INVALID_NBR_ARGS "Invalid number of arguments\n" 
# define NULL_MAP "NULL map argument\n"
# define INVALID_TYPE_ARGS "Invalid type of arguments\n"
# define INCONSISTENT_MAP_WIDTH "Map has an inconsistent width\n"
# define INVALID_ENTITY "Invalid entity on map's file\n"
# define INVALID_FORMAT "Invalid map format\n"
# define MAP_NOT_CLOSED "Map is not closed by walls\n"
# define INVALID_NBR_EXITS "Invalid number of Exits (E)\n"
# define NO_COLLECTIBLES "Map doesn't have any Collectible (C)\n"
# define INVALID_NBR_PLAYERS "Invalid number of Starting Positions (P)\n"
# define UNACHIEVABLE_ENTITIES "Map has unachievable entities\n"
# define INVALID_MAP_FILE "Invalid map file extension\n"
# define OPEN_MAP_FILE_ERR "Failed to open map's file\n"
# define EMPTY_MAP_FILE "Map file is empty\n"
# define WALL_XPM_ERR "Failed to open wall image\n"
# define FLOOR_XPM_ERR "Failed to open floor image\n"
# define PLAYER_XPM_ERR "Failed to open player image\n"
# define COLLECTIBLE_XPM_ERR "Failed to open collectible image\n"
# define EXIT_XPM_ERR "Failed to open exit image\n"

#endif
