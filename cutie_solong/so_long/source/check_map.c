/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:52:01 by klinn             #+#    #+#             */
/*   Updated: 2024/01/24 19:43:01 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	check_file_extension(char *map_file)
{
	size_t	i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(".ber", &map_file[i], 4) == 0)
		return (true);
	return (false);
}

void	check_map_width(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.map[y][x] != '\n' && game->map.map[y][x] != '\0')
			x++;
		if (x != (game->map.width - 1))
			clean_and_exit(game, INCONSISTENT_MAP_WIDTH);
		y++;
	}
}

void	check_elements(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	if (game->map.exit == 0 || game->map.exit > 1)
		clean_and_exit(game, INVALID_NBR_EXITS);
	if (game->map.collectibles == 0)
		clean_and_exit(game, NO_COLLECTIBLES);
	if (game->map.player == 0 || game->map.player > 1)
		clean_and_exit(game, INVALID_NBR_PLAYERS);
	while (++x < game->map.height)
	{
		y = -1;
		while (++y < (game->map.width - 1))
		{
			if ((ft_strchr(VALID_ENTITIES, game->map.map[x][y])) == 0)
			{
				game->charformat = 1;
				clean_and_exit(game, INVALID_TYPE_ARGS);
			}
		}
	}
}

void	check_surrounded_wall(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.height)
	{
		y = 0;
		while (y++ < (game->map.width - 1))
			if (game->map.map[0][y - 1] != '1')
				clean_and_exit(game, MAP_NOT_CLOSED);
		if (game->map.map[x][0] != '1' || game->map.map[x][y - 2] != '1')
			clean_and_exit(game, MAP_NOT_CLOSED);
		x++;
	}
	y = 0;
	while (y < (game->map.width - 1))
	{
		if (game->map.map[x - 1][y] != '1')
			clean_and_exit(game, MAP_NOT_CLOSED);
		y++;
	}
}
