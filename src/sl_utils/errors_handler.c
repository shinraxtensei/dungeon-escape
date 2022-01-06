/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:10:30 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/06 17:51:17 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	free_map(t_meta_data *game)
{
	int	i;

	printf ("map error, 9ad l map asahbi !!");
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit(0);
}

int	check_colums(char *row, int *c, int *p, int *e)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1' && row[i] != '0' && row[i] != 'E'
			&& row[i] != 'P' && row[i] != 'C')
			return (0);
		if (row[i] == 'C')
			*c += 1;
		else if (row[i] == 'P')
			*p += 1;
		else if (row[i] == 'E')
			*e += 1;
		i++;
	}
	return (1);
}

int	check_walls(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	map_checker(t_meta_data *game)
{
	int	i;
	int	p;
	int	e;
	int	c;

	i = -1;
	p = 0;
	e = 0;
	c = 0;
	while (game->map[++i])
	{
		if (game->dimensions.x == game->dimensions.y)
			free_map(game);
		if (game->map[i][0] != '1'
				|| game->map[i][game->dimensions.x - 1] != '1'
				|| ft_strlen(game->map[i]) != game->dimensions.x)
			free_map(game);
		if (i == 0 || i == game->dimensions.y - 1)
			if (!check_walls(game->map[i]))
				free_map(game);
		if (!check_colums(game->map[i], &c, &p, &e))
			free_map(game);
	}
	if (p != 1 || c < 1 || e < 1)
		free_map(game);
}
