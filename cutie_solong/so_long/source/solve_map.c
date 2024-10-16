/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:52:44 by klinn             #+#    #+#             */
/*   Updated: 2024/02/15 18:33:12 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**tmp_matrix(t_game *game)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_calloc((game->map.height + 1), sizeof(char *));
	if (!tmp)
		clean_and_exit(game, MALLOC_ERR);
	while (i < game->map.height)
	{
		tmp[i] = ft_strdup(game->map.map[i]);
		if (!tmp[i])
		{
			ft_free_matrix(tmp);
			clean_and_exit(game, MALLOC_ERR);
		}
		i += 1;
	}
	return (tmp);
}

bool	flood_fill(t_map *map, t_point cur_pos, char **map_matrix)
{
	if (map_matrix[cur_pos.y][cur_pos.x] == WALL)
	{
		return (false);
	}
	else if (map_matrix[cur_pos.y][cur_pos.x] == COLLECTIBLE)
	{
		map->flood_coins += 1;
	}
	else if (map_matrix[cur_pos.y][cur_pos.x] == EXIT)
	{
		map->flood_exit += 1;
	}
	map_matrix[cur_pos.y][cur_pos.x] = WALL;
	flood_fill(map, (t_point){cur_pos.x + 1, cur_pos.y}, map_matrix);
	flood_fill(map, (t_point){cur_pos.x - 1, cur_pos.y}, map_matrix);
	flood_fill(map, (t_point){cur_pos.x, cur_pos.y + 1}, map_matrix);
	flood_fill(map, (t_point){cur_pos.x, cur_pos.y - 1}, map_matrix);
	return (map->flood_coins == map->collectibles && map->flood_exit == 1);
}

void	solve_map(t_game *game)
{
	char	**fake_matrix;

	fake_matrix = tmp_matrix(game);
	if (!flood_fill(&game->map, game->map.player_pos, fake_matrix))
	{
		ft_free_matrix(fake_matrix);
		clean_and_exit(game, UNACHIEVABLE_ENTITIES);
	}
	ft_free_matrix(fake_matrix);
}
