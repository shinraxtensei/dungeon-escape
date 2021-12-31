#include"../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	printf("map error");
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit(0);
}



char **map_reader(int fd, meta_data *game)
{  
char *tmp;
char *map_1d = "";
char **map;
while (1)
    {
        tmp = get_next_line(fd);
        if(!tmp)
            break;
        game->dimensions.y++;
        map_1d = ft_strjoin(map_1d , tmp);
    }
    map = ft_split(map_1d , '\n');
    return(map);
}








void    print_img(int i, int j,meta_data *game)
{
        game->img= mlx_xpm_file_to_image(game->mlx,game->hero_path, &game->dimensions.x, &game->dimensions.y);
        mlx_put_image_to_window(game->mlx,game->win ,game->img , j * 40, i * 40);
}




int    render_map(meta_data *game)
{
    int i =-1;
    int j ;
    static int checker;

    while(game->map[++i])
    {
            j = -1 ;
            while (game->map[i][++j])
            {
                if (checker == 0)
                {
                    if(game->map[i][j]== '1')
                    {
                        game->hero_path = "assets/wall2.xpm";
                        print_img( i, j ,game);

                    }
                    if(game->map[i][j]== '0')
                    {
                        game->hero_path = "assets/floor.xpm";
                        print_img( i, j ,game);
                    }
                    if(game->map[i][j]== 'P')
                    {
                        game->hero_path = "assets/hero_down.xpm";
                        game->hero_pos.x = i;
                        game->hero_pos.y = j;
                        print_img(i, j ,game);
                    }
                    if(game->map[i][j]== 'E')
                    {
                        game->exit_pos.x = i;
                        game->exit_pos.y = j;
                        game->hero_path = "assets/exit.xpm";
                        print_img( i, j ,game);
                    }
                    if(game->map[i][j]== 'C')
                    {
                        game->exit_pos.x = i;
                        game->exit_pos.y = j;
                        game->hero_path = "assets/chest.xpm";
                        print_img( i, j ,game);
                    }
                }
                else
                {
                    if (game->map[i][j] == 'P')
                    {
                        game->hero_img = "assets/hero_up.xpm";
                        game->hero_path = game->hero_img ;
                        game->hero_pos.x = i;
                        game->hero_pos.y = j;
                        print_img(i, j ,game);
                        game->hero_path = "assets/floor.xpm";
                        print_img(game->old_pos.x , game->old_pos.y , game);
                    }
                }
            }
    }
    checker = 1;
    return (0);
}
















void    map_manager(char *file , meta_data *game)
{
    int fd = open(file, O_RDONLY);
    game->dimensions.y = 0;
    game->map = map_reader(fd , game);
    
    game->dimensions.x = ft_strlen(game->map[0]);
    game->win= mlx_new_window(game->mlx,game->dimensions.x* 40 , game->dimensions.y * 40, "test");
    render_map(game);
}