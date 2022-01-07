/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 14:54:07 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/07 10:30:52 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	main(int ac, char **av)
{
	t_meta_data	game;

	if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		{
			printf("fix the path bruh");
			exit(1);
		}
		game.mlx = mlx_init();
		map_manager (av[1], &game);
		mlx_loop_hook (game.mlx, render_map, &game);
		mlx_hook (game.win, 02, 0, keys_manager, &game);
		mlx_hook (game.win, 17, 0, close_game, &game);
		mlx_loop (game.mlx);
	}
	return (0);
}
