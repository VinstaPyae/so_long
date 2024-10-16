/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:52:20 by klinn             #+#    #+#             */
/*   Updated: 2024/02/15 18:04:24 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_rows_cols(char *map_file, t_game *game)
{
	int		count;
	int		map_fd;
	char	*temp;

	if (!check_file_extension(map_file))
		clean_and_exit(game, INVALID_MAP_FILE);
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		clean_and_exit(game, OPEN_MAP_FILE_ERR);
	count = 0;
	temp = get_next_line(map_fd);
	if (!temp)
		clean_and_exit(game, EMPTY_MAP_FILE);
	game->map.width = ft_strlen(temp);
	while (temp)
	{
		count += 1;
		free(temp);
		temp = get_next_line(map_fd);
	}
	if (count == 0)
		clean_and_exit(game, EMPTY_MAP_FILE);
	game->map.height = count;
	close(map_fd);
}

void	input_map_data(char *map_file, t_game *game)
{
	int	i;
	int	map_fd;

	if (!check_file_extension(map_file))
		clean_and_exit(game, INVALID_MAP_FILE);
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		clean_and_exit(game, OPEN_MAP_FILE_ERR);
	i = 0;
	game->map.map = malloc((game->map.height + 1) * sizeof(char *));
	while (i < (game->map.height))
		game->map.map[i++] = get_next_line(map_fd);
	game->map.map[i] = NULL;
	close(map_fd);
}

void	get_map_elements(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < game->map.height)
	{
		y = -1;
		while (++y < (game->map.width - 1))
		{
			if ((ft_strchr(VALID_ENTITIES, game->map.map[x][y])) == 0)
				game->charformat = 1;
			if (game->map.map[x][y] == EXIT)
			{
				game->map.exit += 1;
				game->map.exit_pos = (t_point){x, y};
			}
			else if (game->map.map[x][y] == COLLECTIBLE)
				game->map.collectibles += 1;
			else if (game->map.map[x][y] == PLAYER)
			{
				game->map.player += 1;
				game->map.player_pos = (t_point){y, x};
			}
		}
	}
}

void	get_map(char *map_file, t_game *game)
{
	get_rows_cols(map_file, game);
	input_map_data(map_file, game);
	check_map_width(game);
	get_map_elements(game);
	check_elements(game);
	check_surrounded_wall(game);
}
