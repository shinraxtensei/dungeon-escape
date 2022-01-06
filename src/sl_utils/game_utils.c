/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:39:59 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/06 17:20:43 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	render_player(t_meta_data *game, int i, int j)
{
	game->img_path = "assets/hero_down.xpm";
	game->hero_pos.x = i;
	game->hero_pos.y = j;
	print_img(i, j, game);
}

void	collec_exit(t_meta_data *game, int i, int j)
{
	if (game->map[i][j] == 'E')
	{
		game->img_path = "assets/exit.xpm";
		print_img(i, j, game);
	}
	else if (game->map[i][j] == 'C')
	{
		game->count++;
		game->img_path = "assets/behelet1.xpm";
		print_img(i, j, game);
	}
}

void	wall_floor(t_meta_data *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		game->img_path = "assets/wall2.xpm";
		print_img(i, j, game);
	}
	else if (game->map[i][j] == '0')
	{
		game->img_path = "assets/floor.xpm";
		print_img(i, j, game);
	}
}

int	close_game(t_meta_data *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	printf("game closed !!");
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}
