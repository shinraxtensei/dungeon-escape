#include"../so_long.h"


static void    render_player(t_meta_data *game)
{
	game->img_path = game->hero_img;
	print_img(game->hero_pos.x,game->hero_pos.y ,game);
}


void    move_up(t_meta_data *game)
{
		game->img_path = "assets/floor.xpm";
		game->hero_img = "assets/hero_up.xpm";
		if(game->map[game->hero_pos.x - 1][game->hero_pos.y ] != '1' 
		&& (game->map[game->hero_pos.x -1][game->hero_pos.y  ] != 'E'  || game->count == 0))
		{
			if(game->map[game->hero_pos.x -1][game->hero_pos.y  ] == 'C')
				game->count--;
			if(game->map[game->hero_pos.x -1][game->hero_pos.y  ] == 'E')
				exit(0);
			game->map[game->hero_pos.x] [game->hero_pos.y ] = '0';
			print_img(game->hero_pos.x,game->hero_pos.y ,game);
			 game->hero_pos.x--;
			game->map[game->hero_pos.x  ][game->hero_pos.y ] = 'P';
			render_player(game);
		}
}

void    move_down(t_meta_data *game)
{
		game->img_path = "assets/floor.xpm";
		game->hero_img = "assets/hero_down.xpm";
		if(game->map[game->hero_pos.x + 1][game->hero_pos.y ] != '1'
	   && (game->map[game->hero_pos.x +1][game->hero_pos.y  ] != 'E' || game->count == 0 ))
		{
			if(game->map[game->hero_pos.x + 1][game->hero_pos.y  ] == 'C')
				game->count--;
			if(game->map[game->hero_pos.x +1][game->hero_pos.y  ] == 'E')
				exit(0);
			game->map[game->hero_pos.x] [game->hero_pos.y ] = '0';
			print_img(game->hero_pos.x,game->hero_pos.y ,game);
			 game->hero_pos.x++;
			game->map[game->hero_pos.x  ][game->hero_pos.y ] = 'P';
			render_player(game);
		}
}

void    move_left(t_meta_data *game)
{
		game->img_path = "assets/floor.xpm";
		game->hero_img = "assets/hero_left.xpm";
		if(game->map[game->hero_pos.x ][game->hero_pos.y -1 ] != '1'
		&& (game->map[game->hero_pos.x ][game->hero_pos.y - 1 ] != 'E' || game->count == 0))

		{
			if(game->map[game->hero_pos.x ][game->hero_pos.y  -1] == 'C')
				game->count--;
			if(game->map[game->hero_pos.x][game->hero_pos.y - 1 ] == 'E')
				exit(0);
			game->map[game->hero_pos.x] [game->hero_pos.y ] = '0';
			print_img(game->hero_pos.x,game->hero_pos.y ,game);
			 game->hero_pos.y--;
			game->map[game->hero_pos.x  ][game->hero_pos.y ] = 'P';
			render_player(game);

		}
}

void    move_right(t_meta_data *game)
{
		game->img_path = "assets/floor.xpm";
		game->hero_img = "assets/hero_right.xpm";
		if(game->map[game->hero_pos.x ][game->hero_pos.y +1 ] != '1'
		&& (game->map[game->hero_pos.x ][game->hero_pos.y + 1 ] != 'E' || game->count == 0 ))
		{
			if(game->map[game->hero_pos.x ][game->hero_pos.y + 1] == 'C')
				game->count--;
			 if(game->map[game->hero_pos.x][game->hero_pos.y + 1 ] == 'E')
				exit(0);
			game->map[game->hero_pos.x] [game->hero_pos.y ] = '0';
			print_img(game->hero_pos.x,game->hero_pos.y ,game);
			 game->hero_pos.y++;
			game->map[game->hero_pos.x  ][game->hero_pos.y ] = 'P';
			render_player(game);

		}
}
