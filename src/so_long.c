/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 14:54:07 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/06 11:41:45 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_meta_data	game;

	if (ac == 2)
	{
		if (!ft_strstr(av[1], ".ber"))
		{
			printf("fix the path bruh");
			exit(1);
		}
		game.mlx = mlx_init();
		map_manager (av[1], &game);
		mlx_hook (game.win, 02, 0, keys_manager, &game);
		mlx_loop_hook (game.mlx, render_map, &game);
		mlx_hook (game.win, 17, 0, close_game, &game);
		mlx_loop (game.mlx);
	}
	return (0);
}
