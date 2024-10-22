/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:13:57 by pzaw              #+#    #+#             */
/*   Updated: 2024/10/17 15:40:11 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mpp mp_info;

	if (argc == 2)
	{
		put_map(&mp_info, argv);
		check_map(&mp_info);
	}
	else
		ft_putstr_fd("\033[1;31m🛑Error:\033[0mPut MAP File\n", 1);
}