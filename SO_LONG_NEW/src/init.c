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

void	init_tiles(t_game *game)
{
	game->tiles.collectible = NULL;
	game->tiles.exit = NULL;
	game->tiles.floor = NULL;
	game->tiles.player = NULL;
	game->tiles.wall = NULL;
	game->moves = -1;
}

void	init_checker(t_game *game)
{
	game->elements = 0;
	game->map.surrounded_wall = 0;
	game->map.flood_coins = 0;
	game->map.flood_exit = 0;
}

void	init_mlx(t_game *game)
{
	int	width;
	int	height;

	width = (game->map.width - 1) * TILE_SIZE;
	height = game->map.height * TILE_SIZE;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_exit(game, "Failed to initialize mlx!\n");
	game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, "so_long");
	if (!game->win_ptr)
		error_exit(game, "Failed to open window!\n");
}

void	init_xpm(t_game *game)
{
	int	t;

	t = TILE_SIZE;
	game->mlx_inited = 1;
	game->tiles.wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL_TILE, &t, &t);
	if (!game->tiles.wall)
		error_exit(game, "Failed to show wall image!\n");
	game->tiles.floor = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR_TILE, &t,
			&t);
	if (!game->tiles.floor)
		error_exit(game, "Failed to show floor image!\n");
	game->tiles.collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE_TILE, &t, &t);
	if (!game->tiles.collectible)
		error_exit(game, "Failed to show collectible image!\n");
	game->tiles.player = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER_TILE, &t,
			&t);
	if (!game->tiles.player)
		error_exit(game, "Failed to show wall image!\n");
	game->tiles.exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_TILE, &t, &t);
	if (!game->tiles.exit)
		error_exit(game, "Failed to show wall image!\n");
}
