/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:16:29 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/02 15:36:28 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

char	**map_reader(int fd, t_meta_data *game)
{
	char	*tmp;
	char	*map_1d;
	char	**map;

	game->dimensions.x = 0;
	map_1d = "";
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		game->dimensions.y++;
		map_1d = ft_strjoin(map_1d, tmp);
	}
	map = ft_split(map_1d, '\n');
	game->dimensions.x = ft_strlen(map[0]);
	return (map);
}

void	print_img(int i, int j, t_meta_data *game)
{
	int	a;
	int	b;

	game->img = mlx_xpm_file_to_image(game->mlx, game->img_path, &a, &b);
	mlx_put_image_to_window(game->mlx, game->win, game->img, j * 40, i * 40);
}

void	animation(t_meta_data *game, int i, int j)
{
	game->img_path = "assets/behelet1.xpm";
	print_img(i, j, game);
	game->img_path = "assets/behelet2.xpm";
	print_img(i, j, game);
	game->img_path = "assets/behelet3.xpm";
	print_img(i, j, game);
	game->img_path = "assets/behelet4.xpm";
	print_img(i, j, game);
	game->img_path = "assets/behelet5.xpm";
	print_img(i, j, game);
	game->img_path = "assets/behelet6.xpm";
	print_img(i, j, game);
	game->img_path = "assets/behelet7.xpm";
	print_img(i, j, game);
}

static void	wall_floor(t_meta_data *game, int i, int j)
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

static void	collec_exit(t_meta_data *game, int i, int j)
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

int	render_map(t_meta_data *game)
{
	int			i;
	int			j;
	static int	checker;

	i = -1;
	while (game->map[++i])
	{
		j = -1 ;
		while (game->map[i][++j])
		{
			if (checker == 0)
			{
				if (game->map[i][j] == '1' || game->map[i][j] == '0')
					wall_floor(game, i, j);
				else if (game->map[i][j] == 'E' || game->map[i][j] == 'C')
					collec_exit(game, i, j);
				else if (game->map[i][j] == 'P')
				{
					game->img_path = "assets/hero_down.xpm";
					game->hero_pos.x = i;
					game->hero_pos.y = j;
					print_img(i, j, game);
				}
			}
		}
	}
	checker = 1;
	return (0);
}

void	map_manager(char *file, t_meta_data *game)
{
	int fd = open(file, O_RDONLY);
	game->map = map_reader(fd, game);
	game->count = 0;
	map_checker(game);
	game->win = mlx_new_window(game->mlx, game->dimensions.x * 40, game->dimensions.y * 40, "test");
	render_map(game);
}
