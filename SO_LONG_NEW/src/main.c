#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_map(&game);
		init_checker(&game);
		put_map(argv[1], &game);
		check_map_playable(&game);
		init_mlx(&game);
		render_map(&game);
		key_hook(&game);
	}
	else
		error_exit(&game, "Map not found!!\n");
}