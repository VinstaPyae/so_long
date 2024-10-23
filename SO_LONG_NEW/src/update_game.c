#include "../inc/so_long.h"

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

	y = game->map.player_pos.y;
	x = game->map.player_pos.x;
	if (game->map.map[y][x] == 'C')
	{
		game->map.map[y][x] = '0';
		game->map.collectibles -= 1;
		return ;
	}
	if (game->map.map[y][x] == 'E'
		&& game->map.collectibles == 0)
	{
		ft_printf("You Win!! Get out now!\n");
		quit_game(game);
	}
}
void	update_map(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.floor,
		TILE_SIZE * game->map.player_pos.x, TILE_SIZE
		* game->map.player_pos.y);
}

void	update_player_pos(t_game *game, bool horizontal, int length)
{
	if (horizontal == true)
	{
		if (game->map.map[game->map.player_pos.y][game->map.player_pos.x
			+ length] == '1')
			return ;
		if (game->map.map[game->map.player_pos.y][game->map.player_pos.x
			+ length] == 'E' && game->map.collectibles != 0)
			return ;
		update_map(game);
		game->map.player_pos.x += length;
	}
	else
	{
		if (game->map.map[game->map.player_pos.y + length]
			[game->map.player_pos.x] == '1')
			return ;
		if (game->map.map[game->map.player_pos.y + length]
		[game->map.player_pos.x] == 'E' && game->map.collectibles != 0)
			return ;
		update_map(game);
		game->map.player_pos.y += length;
	}
	if_touchable_tiles(game);
	update_map(game);
	render_player_tiles(game);
}
