/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:13:05 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/02 15:16:21 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

int	game_keys(t_meta_data *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	keys_manager(int keycode, t_meta_data *game)
{
	if (keycode == 53)
		game_keys(game);
	if (keycode == 13)
		move_up(game);
	if (keycode == 1)
		move_down(game);
	if (keycode == 0)
		move_left(game);
	if (keycode == 2)
		move_right(game);
	return (0);
}
