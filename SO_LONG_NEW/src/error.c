#include "../inc/so_long.h"

void	ft_free_mem(char **tab)
{
	size_t	i;

	if (!tab)
		return;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	clean_tiles(t_game *game)
{
	if (game->tiles.wall)
		mlx_destroy_image(game->mlx_ptr, game->tiles.wall);
	if (game->tiles.floor)
		mlx_destroy_image(game->mlx_ptr, game->tiles.floor);
	if (game->tiles.player)
		mlx_destroy_image(game->mlx_ptr, game->tiles.player);
	if (game->tiles.collectible)
		mlx_destroy_image(game->mlx_ptr, game->tiles.collectible);
	if (game->tiles.exit)
		mlx_destroy_image(game->mlx_ptr, game->tiles.exit);
}

void	clean_game(t_game *game)
{
	if (!game)
		return ;
	if (game->elements == 0)
		clean_tiles(game);
	if (game->mlx_inited == 1)
	{
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
		{
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
		}
	}
	if (game->map.map)
		ft_free_mem(game->map.map);
}

void	error_exit(t_game *game, char *err_msg)
{
	clean_game(game);
	ft_putstr_fd("\n[Error] >> ", STDERR_FILENO);
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}