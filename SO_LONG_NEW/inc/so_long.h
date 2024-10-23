#ifndef SO_LONG_H
# define SO_LONG_H

#ifndef BUFFSIZE
# define BUFFSIZE 10000
#endif

# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/minilibx/minilibx-linux/mlx.h"
# include "values.h"

typedef struct s_point {
	int	x;
	int	y;
}			   t_point;

typedef struct s_map {
	char			**map;
	char				*buff;
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
}		t_map;

typedef struct s_tiles {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}				t_tiles;

typedef struct s_game {
	t_map		map;
	t_tiles		tiles;
	void		*mlx_ptr;
	void		*win_ptr;
	int			moves;
	int			mlx_inited;
	int			elements;
}		t_game;

void	put_map(char *mp_file, t_game *game);
void	ft_free_mem(char **tab);
void	error_exit(t_game *game, char *err_msg);
void	clean_game(t_game *game);
void	init_map(t_game *game);
void	init_checker(t_game *game);
void	init_xpm(t_game *game);
void	init_mlx(t_game *game);
void	check_map(t_game *game);
int	file_validation(char *mp_file);
void	check_map_playable(t_game *game);
void	render_map(t_game *game);
void	key_hook(t_game *game);
void	render_map(t_game *game);
void	update_player_pos(t_game *game, bool horizontal, int length);
int	quit_game(t_game *game);
void	render_player_tiles(t_game *game);
void	init_tiles(t_game *game);

#endif