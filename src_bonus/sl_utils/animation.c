/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:34:47 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/06 09:19:47 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	render_animation(t_meta_data *game, int i, int j)
{
	int	a;
	int	b;

	game->animation_img = mlx_xpm_file_to_image(game->mlx \
			, game->animation_path, &a, &b);
	mlx_put_image_to_window(game->mlx, game->win \
			, game->animation_img, j * 40, i * 40);
}

static void	frame_update(t_meta_data *game)
{
	if (game->frame < 70)
		game->frame++;
	else
		game->frame = 0;
}

static void	animate_collect(t_meta_data *game, int frame)
{
	if (frame == 0)
		game->animation_path = "assets/behelet1.xpm";
	else if (frame == 20)
		game->animation_path = "assets/behelet2.xpm";
	else if (frame == 30)
		game->animation_path = "assets/behelet3.xpm";
	else if (frame == 40)
		game->animation_path = "assets/behelet4.xpm";
	else if (frame == 50)
		game->animation_path = "assets/behelet5.xpm";
	else if (frame == 60)
		game->animation_path = "assets/behelet6.xpm";
	else if (frame == 70)
		game->animation_path = "assets/behelet7.xpm";
}

void	animate(t_meta_data *game)
{
	frame_update(game);
	animate_collect(game, game->frame);
}
