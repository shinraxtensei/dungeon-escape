/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:16:29 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/06 08:39:52 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

char	**map_reader(int fd, t_meta_data *game)
{
	char	*tmp;
	char	*map_1d;
	char	**map;

	game->dimensions.x = 0;
	map_1d = ft_strdup("");
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		game->dimensions.y++;
		map_1d = ft_strjoin(map_1d, tmp);
	}
	map = ft_split(map_1d, '\n');
	free(tmp);
	free(map_1d);
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

int	render_map(t_meta_data *game, int i, int j)
{
	static int	checker;

	i = -1 ;
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
					render_player(game, i, j);
			}
		}
	}
	checker = 1;
	return (0);
}

void	map_manager(char *file, t_meta_data *game)
{
	int	i;
	int	j;
	int	fd;

	i = -1;
	j = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(1);
	game->map = map_reader(fd, game);
	game->count = 0;
	map_checker(game);
	game->win = mlx_new_window(game->mlx, game->dimensions.x * 40 \
	, game->dimensions.y * 40, "test");
	render_map(game, i, j);
}
