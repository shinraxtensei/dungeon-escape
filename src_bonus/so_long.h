/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:05:09 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/04 13:09:08 by ahouari          ###   ########.fr       */
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
	int			frame;
	int			movements_counter;
	int			count;
	void		*mlx;
	void		*win;
	char		**map;
	void		*img;
	void		*hero_img;
	void		*animation_img;
	char		*img_path;
	char		*hero_path;
	char		*animation_path;

	t_pos_dim	dimensions;
	t_pos_dim	hero_pos;
}t_meta_data;

char	**map_reader(int fd, t_meta_data *game);
void	map_manager(char *file, t_meta_data *game);
int		render_map(t_meta_data *game, int i, int j);
void	print_img(int i, int j, t_meta_data *game);
void	free_map(t_meta_data *game);
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
void	movements_counter(t_meta_data *game);
void	init_player(t_meta_data *game, int i, int j);
//utils
void	render_player(t_meta_data *game, int i, int j);
void	collec_exit(t_meta_data *game, int i, int j);
void	wall_floor(t_meta_data *game, int i, int j);
int		close_game(t_meta_data *game);

// animation
void	animate(t_meta_data *game);
void	render_animation(t_meta_data *game, int i, int j);
#endif
