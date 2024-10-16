/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:52:49 by klinn             #+#    #+#             */
/*   Updated: 2024/02/15 18:29:04 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	quit_game(t_game *game)
{
	clean_game(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	if_touchable_tiles(t_game *game)
{
	int	x;
	int	y;

	x = game->map.player_pos.y;
	y = game->map.player_pos.x;
	if (game->map.map[x][y] == COLLECTIBLE)
	{
		game->map.map[x][y] = OPEN_SPACE;
		game->map.collectibles -= 1;
		return ;
	}
	if (game->map.map[x][y] == EXIT
		&& game->map.collectibles == 0)
	{
		ft_printf(WIN_MSG);
		quit_game(game);
	}
}

void	update_map(t_game *game)
{
	if (game->map.collectibles == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.exit,
			TILE_SIZE * game->map.exit_pos.y, TILE_SIZE * game->map.exit_pos.x);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.floor,
			TILE_SIZE * game->map.player_pos.x, TILE_SIZE
			* game->map.player_pos.y);
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.floor,
			TILE_SIZE * game->map.player_pos.x, TILE_SIZE
			* game->map.player_pos.y);
	}
}

void	update_player_pos(t_game *game, bool horizontal, int length)
{
	if (horizontal == true)
	{
		if (game->map.map[game->map.player_pos.y][game->map.player_pos.x
			+ length] == WALL)
			return ;
		update_map(game);
		game->map.player_pos.x += length;
	}
	else
	{
		if (game->map.map[game->map.player_pos.y + length]
			[game->map.player_pos.x] == WALL)
			return ;
		update_map(game);
		game->map.player_pos.y += length;
	}
	if_touchable_tiles(game);
	update_map(game);
	render_player_tiles(game);
}
