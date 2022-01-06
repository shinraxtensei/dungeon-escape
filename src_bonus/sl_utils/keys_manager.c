/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:13:05 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/04 12:39:30 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

int	keys_manager(int keycode, t_meta_data *game)
{
	game->img_path = "assets/floor.xpm";
	if (keycode == 53)
		close_game(game);
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
