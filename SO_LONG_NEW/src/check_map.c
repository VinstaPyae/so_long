#include "../inc/so_long.h"

int	file_validation(char *mp_file)
{
	char	*file_ext;

	file_ext = ft_strrchr(mp_file, '.');
	if (!file_ext || ft_strncmp(file_ext, ".ber", 5))
		return (0);
	return (1);
}

int	is_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i])
	{
		if (ft_strlen(game->map.map[i]) != (size_t)(game->map.width - 1))
			return (0);
		i++;
	}
	return (1);
}

void	check_elements(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	if (game->map.exit == 0 || game->map.exit > 1)
		error_exit(game, "Invalid Exit in Map!\n");
	if (game->map.collectibles == 0)
		error_exit(game, "There are no Collectibles in Map\n");
	if (game->map.player == 0 || game->map.player > 1)
		error_exit(game, "Invalid Player in Map!\n");
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < (game->map.width - 1))
		{
			if ((ft_strchr("ECP01", game->map.map[y][x])) == 0)
			{
				game->elements = 1;
				error_exit(game, "There are Invalid Elements in Map!!\n");
			}
		}
	}
}

void	is_surrounded_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x++ < (game->map.width - 1))
			if (game->map.map[0][x - 1] != '1')
				error_exit(game, "Map is not surrounded by wall!!\n");
		if (game->map.map[y][0] != '1' || game->map.map[y][x - 2] != '1')
			error_exit(game, "Map is not surrounded by wall!!\n");
		y++;
	}
	x = 0;
	while (x < (game->map.width - 1))
	{
		if (game->map.map[y - 1][x] != '1')
			error_exit(game, "Map is not surrounded by wall!!\n");
		x++;
	}
}

void	check_map(t_game *game)
{
	if (!is_rectangular(game))
		error_exit(game, "Map is not rectangular!!\n");
	check_elements(game);
	is_surrounded_wall(game);
}
