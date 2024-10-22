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

void	clean_game(t_game *game)
{
	if (!game)
		return ;
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