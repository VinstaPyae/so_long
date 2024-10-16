/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:52:13 by klinn             #+#    #+#             */
/*   Updated: 2024/02/15 15:16:56 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	if (game->charformat == 0)
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
		ft_free_matrix(game->map.map);
}

void	clean_and_exit(t_game *game, char *err_msg)
{
	clean_game(game);
	ft_putstr_fd("\n[Error] >> ", STDERR_FILENO);
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
