/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:43:22 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/06 09:12:47 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	movements_counter(t_meta_data *game)
{
	int static	movements_count = 1;
	char		*counter;
	char		*message;

	wall_floor(game, 0, 0);
	wall_floor(game, 0, 1);
	wall_floor(game, 0, 2);
	wall_floor(game, 0, 3);
	message = "movements : ";
	counter = ft_itoa(movements_count);
	message = ft_strjoin(message, counter);
	mlx_string_put(game->mlx, game->win, 5, 5, 0xffffff, message);
	movements_count++;
}

void	move_up(t_meta_data *game)
{
	if (game->map[game->hero_pos.x - 1][game->hero_pos.y] != '1'
	&& (game->map[game->hero_pos.x - 1][game->hero_pos.y] != 'E'
	|| game->count == 0))
	{
		if (game->map[game->hero_pos.x - 1][game->hero_pos.y] == 'C')
			game->count--;
		if (game->map[game->hero_pos.x - 1][game->hero_pos.y] == 'E'
		|| game->map[game->hero_pos.x - 1][game->hero_pos.y] == 'X')
			close_game(game);
		game->map[game->hero_pos.x][game->hero_pos.y] = '0';
		print_img(game->hero_pos.x, game->hero_pos.y, game);
		game->hero_pos.x--;
		game->hero_path = "assets/hero_up.xpm";
		game->map[game->hero_pos.x][game->hero_pos.y] = 'P';
		render_player(game, game->hero_pos.x, game->hero_pos.y);
		movements_counter(game);
	}
}

void	move_down(t_meta_data *game)
{
	if (game->map[game->hero_pos.x + 1][game->hero_pos.y] != '1'
	&& (game->map[game->hero_pos.x +1][game->hero_pos.y] != 'E'
	|| game->count == 0))
	{
		if (game->map[game->hero_pos.x + 1][game->hero_pos.y] == 'C')
			game->count--;
		if (game->map[game->hero_pos.x + 1][game->hero_pos.y] == 'E'
		|| game->map[game->hero_pos.x + 1][game->hero_pos.y] == 'X')
			close_game(game);
		game->map[game->hero_pos.x][game->hero_pos.y] = '0';
		print_img(game->hero_pos.x, game->hero_pos.y, game);
		game->hero_pos.x++;
		game->hero_path = "assets/hero_down.xpm";
		game->map[game->hero_pos.x][game->hero_pos.y] = 'P';
		render_player(game, game->hero_pos.x, game->hero_pos.y);
		movements_counter(game);
	}
}

void	move_left(t_meta_data *game)
{
	if (game->map[game->hero_pos.x][game->hero_pos.y -1] != '1'
	&& (game->map[game->hero_pos.x][game->hero_pos.y - 1] != 'E'
	|| game->count == 0))
	{
		if (game->map[game->hero_pos.x][game->hero_pos.y - 1] == 'C')
			game->count--;
		if (game->map[game->hero_pos.x][game->hero_pos.y - 1] == 'E'
		|| game->map[game->hero_pos.x][game->hero_pos.y - 1] == 'X')
			close_game(game);
		game->map[game->hero_pos.x][game->hero_pos.y] = '0';
		print_img(game->hero_pos.x, game->hero_pos.y, game);
		game->hero_pos.y--;
		game->hero_path = "assets/hero_left.xpm";
		game->map[game->hero_pos.x][game->hero_pos.y] = 'P';
		render_player(game, game->hero_pos.x, game->hero_pos.y);
		movements_counter(game);
	}
}

void	move_right(t_meta_data *game)
{
	if (game->map[game->hero_pos.x][game->hero_pos.y + 1] != '1'
	&& (game->map[game->hero_pos.x][game->hero_pos.y + 1] != 'E'
	|| game->count == 0))
	{
		if (game->map[game->hero_pos.x][game->hero_pos.y + 1] == 'C')
			game->count--;
		if (game->map[game->hero_pos.x][game->hero_pos.y + 1] == 'E'
		|| game->map[game->hero_pos.x][game->hero_pos.y + 1] == 'X')
			close_game(game);
		game->map[game->hero_pos.x][game->hero_pos.y] = '0';
		print_img(game->hero_pos.x, game->hero_pos.y, game);
		game->hero_pos.y++;
		game->hero_path = "assets/hero_right.xpm";
		game->map[game->hero_pos.x][game->hero_pos.y] = 'P';
		render_player(game, game->hero_pos.x, game->hero_pos.y);
		movements_counter(game);
	}
}
