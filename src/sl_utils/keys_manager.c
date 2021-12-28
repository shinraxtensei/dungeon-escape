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
        printf("---hero moved up--- \n");
        counter++;
        printf("key pressed is : %d !!!\n",counter);
    }
    if(keycode == 1)
    {
        printf("---hero moved down--- \n");
        counter++;
        printf("key pressed is : %d !!!\n",counter);
    }
    if(keycode == 0)
    {
        printf("---hero moved left--- \n");
        counter++;
        printf("key pressed is : %d !!!\n",counter);
    }
    if(keycode == 2)
    {
        printf("---hero moved right--- \n");
        counter++;
        printf("key pressed is : %d !!!\n",counter);
    }
    return(0);
}