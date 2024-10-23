#include "../inc/so_long.h"

void	render_player_tiles(t_game *game)
{
	game->moves += 1;
	ft_printf("number of moves : %d\n", game->moves);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.player,
		TILE_SIZE * game->map.player_pos.x, TILE_SIZE * game->map.player_pos.y);
}

void	render_tiles(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < (game->map.width))
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.wall, TILE_SIZE * x, TILE_SIZE * y);
			else if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.collectible, TILE_SIZE * x, TILE_SIZE * y);
			else if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.exit, TILE_SIZE * x, TILE_SIZE * y);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.floor, TILE_SIZE * x, TILE_SIZE * y);
		}
	}
	render_player_tiles(game);
}

void	render_map(t_game *game)
{
	init_xpm(game);
	render_tiles(game);
}
