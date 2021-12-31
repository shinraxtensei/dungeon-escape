#include"../so_long.h"

int     game_keys(int keycode, meta_data *game)
{
    static int counter = 0; 
    
    if(keycode == 53)
    {
        mlx_destroy_window(game->mlx, game->win );
        exit(0);
    }
    if(keycode == 13)
    {
        
        if(game->map[game->hero_pos.x - 1][game->hero_pos.y ] != '1')
        {
            game->hero_img = "assets/hero_up.xpm";
            game->map[game->hero_pos.x] [game->hero_pos.y ]= '0';
            game->old_pos.x = game->hero_pos.x;
            game->old_pos.y = game->hero_pos.y;
            game->map[game->hero_pos.x - 1 ][game->hero_pos.y ] = 'P';
        }
        counter++;
        printf("key pressed is : %d !!!\n",counter);
    }
    if(keycode == 1)
    {
        game->hero_img = "assets/hero_down.xpm";
        if(game->map[game->hero_pos.x + 1][game->hero_pos.y ] != '1')
        {
            game->map[game->hero_pos.x] [game->hero_pos.y ]= '0';
            game->old_pos.x = game->hero_pos.x;
            game->old_pos.y = game->hero_pos.y;
            game->map[game->hero_pos.x + 1][game->hero_pos.y ] = 'P';
        }
        counter++;
        printf("key pressed is : %d !!!\n",counter);
    }
    if(keycode == 0)
    {
        game->hero_img = "assets/hero_left.xpm";
        if(game->map[game->hero_pos.x ][game->hero_pos.y -1 ] != '1')
        {
            game->map[game->hero_pos.x] [game->hero_pos.y ]= '0';
            game->old_pos.x = game->hero_pos.x;
            game->old_pos.y = game->hero_pos.y;
            game->map[game->hero_pos.x ][game->hero_pos.y  - 1] = 'P';
        }
        counter++;
        printf("key pressed is : %d !!!\n",counter);
    }
    if(keycode == 2)
    {

        game->hero_img = "assets/hero_right.xpm";
        if(game->map[game->hero_pos.x ][game->hero_pos.y +1 ] != '1')
        {
            game->map[game->hero_pos.x] [game->hero_pos.y ]= '0';
            game->old_pos.x = game->hero_pos.x;
            game->old_pos.y = game->hero_pos.y;
            game->map[game->hero_pos.x ][game->hero_pos.y  + 1] = 'P';
        }
        counter++;
        printf("key pressed is : %d !!!\n",counter);
    }
    return(0);
}

