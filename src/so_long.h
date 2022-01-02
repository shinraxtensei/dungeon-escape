/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:05:09 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/02 15:42:34 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include"libft/libft.h"
# include"gnl/get_next_line.h"
# include<mlx.h>
# include<stdio.h>

typedef struct t_pos_dim
{
	int	y;
	int	x;
}t_pos_dim;

typedef struct t_meta_data
{
	int		count;
	void	*mlx;
	void	*win;
	char	**map;
	void	*img;
	char	*img_path ;
	char	*hero_img ;
	t_pos_dim	dimensions;
	t_pos_dim	hero_pos;
}t_meta_data;

void	animation(t_meta_data *game, int i, int j);
int		game_keys(t_meta_data *game);
char	**map_reader(int fd, t_meta_data *game);
void	map_manager(char *file, t_meta_data *game);
int		render_map(t_meta_data *game);
void	print_img(int i, int j, t_meta_data *game);
void	free_map(char **map);
int		keys_manager(int keycode, t_meta_data *game);
void	map_checker(t_meta_data *game);
int		check_colums(char *row, int *c, int *p, int *e);
int		check_walls(char *row);
void	map_checker(t_meta_data *game);
//movements
void	move_down(t_meta_data *game );
void	move_up(t_meta_data *game);
void	move_left(t_meta_data *game);
void	move_right(t_meta_data *game);
#endif
