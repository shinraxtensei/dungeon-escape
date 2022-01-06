/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:43:22 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/04 12:56:41 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	movements_counter(void)
{
	int static	movements_count = 1;

	printf("movements : %d \n", movements_count++);
}

void	move_up(t_meta_data *game)
{
	if (game->map[game->hero_pos.x - 1][game->hero_pos.y] != '1'
	&& (game->map[game->hero_pos.x - 1][game->hero_pos.y] != 'E'
	|| game->count == 0))
	{
		movements_counter();
		if (game->map[game->hero_pos.x - 1][game->hero_pos.y] == 'C')
			game->count--;
		if (game->map[game->hero_pos.x - 1][game->hero_pos.y] == 'E')
		{
			printf("you won !!\n");
			close_game(game);
		}
		game->map[game->hero_pos.x][game->hero_pos.y] = '0';
		print_img(game->hero_pos.x, game->hero_pos.y, game);
		game->hero_pos.x--;
		game->img_path = "assets/hero_up.xpm";
		game->map[game->hero_pos.x][game->hero_pos.y] = 'P';
		print_img(game->hero_pos.x, game->hero_pos.y, game);
	}
}

void	move_down(t_meta_data *game)
{
	if (game->map[game->hero_pos.x + 1][game->hero_pos.y] != '1'
	&& (game->map[game->hero_pos.x +1][game->hero_pos.y] != 'E'
	|| game->count == 0))
	{
		movements_counter();
		if (game->map[game->hero_pos.x + 1][game->hero_pos.y] == 'C')
			game->count--;
		if (game->map[game->hero_pos.x +1][game->hero_pos.y] == 'E')
		{
			printf("you won !!\n");
			close_game(game);
		}
		game->map[game->hero_pos.x][game->hero_pos.y] = '0';
		print_img(game->hero_pos.x, game->hero_pos.y, game);
		game->hero_pos.x++;
		game->img_path = "assets/hero_down.xpm";
		game->map[game->hero_pos.x][game->hero_pos.y] = 'P';
		print_img(game->hero_pos.x, game->hero_pos.y, game);
	}
}

void	move_left(t_meta_data *game)
{
	if (game->map[game->hero_pos.x][game->hero_pos.y -1] != '1'
	&& (game->map[game->hero_pos.x][game->hero_pos.y - 1] != 'E'
	|| game->count == 0))
	{
		movements_counter();
		if (game->map[game->hero_pos.x][game->hero_pos.y - 1] == 'C')
			game->count--;
		if (game->map[game->hero_pos.x][game->hero_pos.y - 1] == 'E')
		{
			printf("you won !!\n");
			close_game(game);
		}
		game->map[game->hero_pos.x][game->hero_pos.y] = '0';
		print_img(game->hero_pos.x, game->hero_pos.y, game);
		game->hero_pos.y--;
		game->img_path = "assets/hero_left.xpm";
		game->map[game->hero_pos.x][game->hero_pos.y] = 'P';
		print_img(game->hero_pos.x, game->hero_pos.y, game);
	}
}

void	move_right(t_meta_data *game)
{
	if (game->map[game->hero_pos.x][game->hero_pos.y + 1] != '1'
	&& (game->map[game->hero_pos.x][game->hero_pos.y + 1] != 'E'
	|| game->count == 0))
	{
		movements_counter();
		if (game->map[game->hero_pos.x][game->hero_pos.y + 1] == 'C')
			game->count--;
		if (game->map[game->hero_pos.x][game->hero_pos.y + 1] == 'E')
		{
			printf("you won !!\n");
			close_game(game);
		}
		game->map[game->hero_pos.x][game->hero_pos.y] = '0';
		print_img(game->hero_pos.x, game->hero_pos.y, game);
		game->hero_pos.y++;
		game->img_path = "assets/hero_right.xpm";
		game->map[game->hero_pos.x][game->hero_pos.y] = 'P';
		print_img(game->hero_pos.x, game->hero_pos.y, game);
	}
}
