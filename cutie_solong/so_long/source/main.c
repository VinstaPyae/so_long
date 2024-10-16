/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:52:34 by klinn             #+#    #+#             */
/*   Updated: 2024/02/15 18:29:51 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_tiles(&game);
		init_map(&game);
		init_checker(&game);
		get_map(argv[1], &game);
		solve_map(&game);
		init_mlx(&game);
		render_map(&game);
		key_hook(&game);
	}
	else if (argc < 2)
		clean_and_exit(NULL, NULL_MAP);
	else 
		clean_and_exit(NULL, INVALID_NBR_ARGS);
	return (EXIT_SUCCESS);
}
