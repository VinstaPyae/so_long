#include "../inc/so_long.h"

void	put_map_data(char *mp_file, t_game *game)
{
	int	mp_fd;
	int	byt_rd;

	mp_fd = open(mp_file, O_RDONLY);
	if (mp_fd == -1)
		error_exit(game, "Map File unable to open!\n");
	game->map.buff = (char *)malloc((BUFFSIZE + 1) * sizeof(char));
	if (!game->map.buff)
	{
		free(game->map.buff);
		error_exit(game, "Map Memory Error!\n");
	}
	byt_rd = read(mp_fd, game->map.buff, BUFFSIZE);
	if (byt_rd == -1)
	{
		free(game->map.buff);
		error_exit(game, "Map File uable to read!\n");
	}
	game->map.map = ft_split(game->map.buff, '\n');
	if (!game->map.map)
		error_exit(game, "Cannot input the Map Data!!\n");
	free(game->map.buff);
}

void	get_wnh(t_game *game)
{
	int	i;

	i = 0;
	game->map.width = ft_strlen(game->map.map[i]);
	while (game->map.map[i])
		i++;
	game->map.height = i;
}

void	get_elements(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < (game->map.width - 1))
		{
			if ((ft_strchr("ECP01", game->map.map[y][x])) == 0)
				game->elements = 1;
			if (game->map.map[y][x] == 'E')
			{
				game->map.exit += 1;
				game->map.exit_pos = (t_point){y, x};
			}
			else if (game->map.map[y][x] == 'C')
				game->map.collectibles += 1;
			else if (game->map.map[y][x] == 'P')
			{
				game->map.player += 1;
				game->map.player_pos = (t_point){x, y};
			}
		}
	}
}

void	put_map(char *mp_file, t_game *game)
{
	if (!file_validation(mp_file))
		error_exit(game, "Invalid Map File!\n");
	put_map_data(mp_file, game);
	get_wnh(game);
	get_elements(game);
	check_map(game);
}