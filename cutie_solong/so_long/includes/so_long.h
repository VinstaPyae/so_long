/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:07:55 by klinn             #+#    #+#             */
/*   Updated: 2024/02/15 17:33:53 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libraries/42_library/libft_42.h"
# include "../libraries/minilibx/minilibx-linux/mlx.h"
# include "messages.h"
# include "values.h"

typedef struct s_point {
	int	x;
	int	y;
}			   t_point;

typedef struct s_map {
	char			**map;
	int				width;
	int				height;
	int				collectibles;
	int				exit;
	int				player;
	int				flood_coins;
	int				flood_exit;
	int				surrounded_wall;
	t_point			player_pos;
	t_point			exit_pos;
}			   t_map;

typedef struct s_tiles {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}				t_tiles;

typedef struct s_game {
	t_map		map;
	void		*mlx_ptr;
	void		*win_ptr;
	t_tiles		tiles;
	int			moves;
	int			mlx_inited;
	int			charformat;
}				t_game;

void	init_mlx(t_game *game);
void	init_map(t_game *game);
void	init_checker(t_game *game);
void 	init_tiles(t_game *game);
void    init_xpm(t_game *game);
void	clean_and_exit(t_game *game, char *err_msg);
void	clean_game(t_game *game);
void	clean_tiles(t_game *game);
bool    check_file_extension(char *map_file);
void    check_map_width(t_game *game);
void	check_elements(t_game *game);
void	check_surrounded_wall(t_game *game);
void    get_rows_cols(char *map_file, t_game *game);
void	input_map_data(char *map_file, t_game *game);
void    get_map_elements(t_game *game);
void    get_map(char *map_file, t_game *game);
char	**tmp_matrix(t_game *game);
bool	flood_fill(t_map *map, t_point cur_pos, char **map_matrix);
void	solve_map(t_game *game);
void	render_tiles(t_game *game);
void    render_player_tiles(t_game *game);
void    render_map(t_game *game);
int		quit_game(t_game *game);
void	if_touchable_tiles(t_game *game);
void	update_map(t_game *game);
void	update_player_pos(t_game *game, bool horizontal, int length);
int		close_btn(t_game *game);
int		handle_keys(int key, t_game *game);
void	key_hook(t_game *game);
#endif
