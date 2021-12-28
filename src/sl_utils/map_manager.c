#include"../so_long.h"

void map_reader(int fd , meta_data game)
{
    char *tmp;
    char *map_1d;
    while (1)
    {
        tmp = get_next_line(fd);
        if(!tmp)
            break;
        map_1d = ft_strjoin(map_1d , tmp);
    }
    game.map = ft_split(map_1d , '\n');
}



void    render_map(meta_data game)
{
int  i = 0;
int j = 0;
while (game.map[i])
{
    j = 0;
    while (game.map[i][j])
    {
        print_map(game.map[i][j], game, i ,j);
        j++;
    }
    i++;
}

}

void    print_map(char c , meta_data game  , int i , int j)
{
if(c == '1')
{
    game.img= mlx_xpm_file_to_image(game.mlx,"../assets/wall.xpm" , &game.dimensions.x, &game.dimensions.y); 
    mlx_put_image_to_window(game.mlx,game.win ,game.img , i * 40, j * 40);
}
else if(c == '0')
{
    game.img= mlx_xpm_file_to_image(game.mlx,"../assets/floor.xpm" , &game.dimensions.x, &game.dimensions.y); 
    mlx_put_image_to_window(game.mlx,game.win ,game.img , i * 40, j * 40);
}
else if(c == 'P')
{
    game.img= mlx_xpm_file_to_image(game.mlx,"../assets/hero.xpm" , &game.dimensions.x, &game.dimensions.y); 
    mlx_put_image_to_window(game.mlx,game.win ,game.img , i * 40, j * 40);
}
}



void    map_manager(int fd , meta_data game)
{
    
    map_reader(fd , game);
    render_map(game);
}