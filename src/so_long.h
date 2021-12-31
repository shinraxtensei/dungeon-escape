#ifndef SO_LONG_H
# define SO_LONG_H

# include"libft/libft.h"
# include"gnl/get_next_line.h"
# include<mlx.h>
#include<stdio.h>








typedef struct pos_dim{
    int y;
    int x;

}pos_dim;

typedef struct meta_data
{
    void *mlx;
    void *win;
    char **map;
    void *img;
    char *hero_path ;
    char *hero_img;
    pos_dim dimensions;
    pos_dim hero_pos;
    pos_dim exit_pos;
    pos_dim old_pos;
}meta_data;

int     game_keys(int keycode, meta_data *game);
char **map_reader(int fd , meta_data *game);
void map_manager(char *file, meta_data *game);
int render_map(meta_data *game);
void print_img(int i, int j,meta_data *game);
void	free_map(char **map);
# endif