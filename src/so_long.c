#include"so_long.h"

int main (int ac  , char **av)
{
if(ac == 2)
{
meta_data game;
game.mlx = mlx_init();
int fd = open(av[1], O_RDONLY);
map_reader(fd, game);
printf("%s", game.map[1]);
// int  i = 0;
// int  j = 0;
// while (game.map[i])
// {
//     j = 0;
//     while (game.map[i][j])
//     {
//         if(game.map[i][j]== '1')
//         {
//             game.img= mlx_xpm_file_to_image(game.mlx,"assets/wall.xpm" , &game.dimensions.x, &game.dimensions.y);
//             mlx_put_image_to_window(game.mlx,game.win ,game.img , i * 40, j * 40);
//         }
//         if(game.map[i][j]== '0')
//         {
//             game.img= mlx_xpm_file_to_image(game.mlx,"assets/floor.xpm" , &game.dimensions.x, &game.dimensions.y);
//             mlx_put_image_to_window(game.mlx,game.win ,game.img , i * 40, j * 40);
//         }
//         if(game.map[i][j]== 'P')
//         {
//             game.img= mlx_xpm_file_to_image(game.mlx,"assets/hero.xpm" , &game.dimensions.x, &game.dimensions.y);
//             mlx_put_image_to_window(game.mlx,game.win ,game.img , i * 40, j * 40);
//         }
//         j++;
//     }
//     i++;
// }
// mlx_loop(game.mlx);
 }
 return(0);
}

