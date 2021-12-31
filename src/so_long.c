#include"so_long.h"







int main (int ac  , char **av)
{
if(ac == 2)
{
meta_data game;

game.mlx = mlx_init();
map_manager(av[1] , &game);
mlx_hook(game.win , 02, 0, game_keys , &game);
mlx_loop_hook(game.mlx, render_map, &game);

mlx_loop(game.mlx);
  }
 return(0);
}

