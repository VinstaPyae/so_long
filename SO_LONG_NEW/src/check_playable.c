#include "../inc/so_long.h"

char	**tmp_map(t_game *game)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_calloc((game->map.height + 1), sizeof(char *));
	if (!tmp)
		error_exit(game, "Map dup fail!!\n");
	while (i < game->map.height)
	{
		tmp[i] = ft_strdup(game->map.map[i]);
		if (!tmp[i])
		{
			ft_free_mem(tmp);
			error_exit(game, "Map duplicate fail!!\n");
		}
		i += 1;
	}
	return (tmp);
}

bool	flood_fill(t_map *map, t_point cur_pos, char **dup_map)
{
	if (dup_map[cur_pos.y][cur_pos.x] == '1')
	{
		return (false);
	}
	else if (dup_map[cur_pos.y][cur_pos.x] == 'C')
	{
		map->flood_coins += 1;
	}
	else if (dup_map[cur_pos.y][cur_pos.x] == 'E')
	{
		map->flood_exit += 1;
	}
	dup_map[cur_pos.y][cur_pos.x] = '1';
	flood_fill(map, (t_point){cur_pos.x + 1, cur_pos.y}, dup_map);
	flood_fill(map, (t_point){cur_pos.x - 1, cur_pos.y}, dup_map);
	flood_fill(map, (t_point){cur_pos.x, cur_pos.y + 1}, dup_map);
	flood_fill(map, (t_point){cur_pos.x, cur_pos.y - 1}, dup_map);
	return (map->flood_coins == map->collectibles && map->flood_exit == 1);
}

void	check_map_playable(t_game *game)
{
	char	**dup_map;

	dup_map = tmp_map(game);
	if (!flood_fill(&game->map, game->map.player_pos, dup_map))
	{
		ft_free_mem(dup_map);
		error_exit(game, "Map is not Playable!!\n");
	}
	ft_free_mem(dup_map);
}