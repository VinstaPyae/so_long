#include "../inc/so_long.h"

int	handle_keys(int key, t_game *game)
{
	if (key == ESC)
		quit_game(game);
	else if (key == W || key == UP)
		update_player_pos(game, false, -1);
	else if (key == A || key == LEFT)
		update_player_pos(game, true, -1);
	else if (key == S || key == DOWN)
		update_player_pos(game, false, 1);
	else if (key == D || key == RIGHT)
		update_player_pos(game, true, 1);
	return (EXIT_SUCCESS);
}

int	close_btn(t_game *game)
{
	quit_game(game);
	exit(EXIT_SUCCESS);
}

void	key_hook(t_game *game)
{
	mlx_hook(game->win_ptr, 17, 0, close_btn, game);
	mlx_key_hook(game->win_ptr, handle_keys, game);
	mlx_loop(game->mlx_ptr);
}
