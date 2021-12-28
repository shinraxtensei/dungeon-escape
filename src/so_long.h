#ifndef SO_LONG_H
# define SO_LONG_H

# include"libft/libft.h"
# include"gnl/get_next_line.h"
# include<mlx.h>
#include<stdio.h>

typedef struct img_dim
{
    int x;
    int y;
} img_dim ;


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
    pos_dim dimensions;
}meta_data;


void map_reader(int fd , meta_data game);
void print_map(char c , meta_data game  , int i , int j);
void map_manager(int fd , meta_data game);
void render_map(meta_data game);
# endif