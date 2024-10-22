#include "../inc/so_long.h"

void	init_map(t_game *game)
{
	game->map.map = NULL;
	game->map.height = 0;
	game->map.width = 0;
	game->map.collectibles = 0;
	game->map.exit = 0;
	game->map.player = 0;
}

void	init_checker(t_game *game)
{
	game->elements = 0;
	game->map.surrounded_wall = 0;
	game->map.flood_coins = 0;
	game->map.flood_exit = 0;
}