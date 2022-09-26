// #include "../../minilibX/libmlx.h"
// #include <math.h>
// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>

// #define X_EVENT_key_hook 2
// #define X_EVENT_KEY_EXIT 17
// #define TEX_WIDTH 64
// #define TEX_HEIGHT 64
// #define MAP_WIDTH 24
// #define MAP_HEIGHT 24
// #define WINDOW_WIDTH 1920
// #define WINDOW_HEIGHT 1080
// #define MOVESPEED 0.5
// #define ROTSPEED 0.5

// #  define K_W 119
// #  define K_A 97
// #  define K_S 115
// #  define K_D 100
// #  define K_P 112
// #  define K_UP 65362
// #  define K_LEFT 65361
// #  define K_DOWN 65364
// #  define K_RIGHT 65363
// #  define K_SHIFT 65505
// #  define ESC 65307
// // #  define ESP 32

// typedef struct	s_img
// {
// 	void	*mlx_img;
// 	int		*data;
// 	int		line_length;
// 	int		bits_per_pixel;
// 	int		endian;
// }				t_img;

// typedef struct s_game
// {
// 	void	*mlx;
// 	void	*win;
// 	t_img	img;
// 	int		*map;
// 	double 	posX;
// 	double	posY; 
// 	double 	dirX;
// 	double	dirY; 
// 	double 	planeX;
// 	double	planeY;
// 	double	ray_dirX;
// 	double	ray_dirY;
// 	double	cameraX;
// 	int 	stepX;
// 	int 	stepY;
// 	int 	hit;
// 	int 	side;
// 	int 	lineHeight;
// 	double 	sideDistX;
// 	double 	sideDistY;
// 	double 	deltaDistX;
// 	double 	deltaDistY;
// 	double 	perpWallDist;
// 	double 	oldDirX;
// 	double 	oldPlaneX;
// 	int 	mapX;
// 	double 	height;
// 	double 	width;
// 	int 	mapY;
// 	int 	drawStart;
// 	int 	drawEnd;
// 	int 	color;
// 	int		**buf;
// 	int		re_buf;
// 	int		texture[8][TEX_HEIGHT * TEX_WIDTH];
// 	int		xorcolor;
// 	int		ycolor;
// 	int		xycolor;
// 	int		tex_number;
// 	double	wall_x;
// 	int		tex_x;
// 	double	step;
// } t_game;


// int	worldMap[MAP_WIDTH][MAP_HEIGHT] =
// 						{
// 							{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
// 							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
// 							{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
// 							{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
// 							{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
// 							{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
// 							{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
// 							{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
// 							{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
// 							{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
// 							{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
// 							{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
// 							{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
// 							{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
// 							{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
// 							{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
// 							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
// 							{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
// 							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
// 							{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
// 							{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
// 							{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
// 							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
// 							{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
// 						};

// void	draw_vertical_line(t_game *game)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y < WINDOW_HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WINDOW_WIDTH)
// 		{
// 			game->img.data[y * WINDOW_WIDTH + x] = game->buf[y][x];
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	init_re_buf(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	if (game->re_buf == 1)
// 	{
// 		i = 0;
// 		while (i < WINDOW_HEIGHT)
// 		{
// 			j = 0;
// 			while (j < WINDOW_WIDTH)
// 			{
// 				game->buf[i][j] = 0;
// 				j++;
// 			}
// 			i++;
// 		}
// 		game->re_buf = 0;
// 	}
// }

// static void	get_which_box_of_the_map_we_re_in(t_game *game)
// {
// 	game->mapX = (int)game->posX;
// 	game->mapY = (int)game->posY;
// }

// static void	get_length_of_ray_from_x_or_y_side_to_next_x_or_y_side(t_game *game)
// {
// 	game->deltaDistX = fabs(1 / game->ray_dirX);
// 	game->deltaDistY = fabs(1 / game->ray_dirY);
// }

// int	calculate_ray_position_and_direction(t_game *game, int x)
// {
// 	game->cameraX = 2.0 * x / (double)WINDOW_WIDTH - 1.0;
// 	game->ray_dirX = game->dirX + game->planeX * game->cameraX;
// 	game->ray_dirY = game->dirY + game->planeY * game->cameraX;
// 	get_which_box_of_the_map_we_re_in(game);
// 	get_length_of_ray_from_x_or_y_side_to_next_x_or_y_side(game);
// 	return (0);
// }

// void	calculate_step(t_game *game)
// {
// 	if (game->ray_dirX < 0)
// 	{
// 		game->stepX = -1;
// 		game->sideDistX = (game->posX - game->mapX) * game->deltaDistX;
// 	}
// 	else
// 	{
// 		game->stepX = 1;
// 		game->sideDistX = (game->mapX + 1.0 - game->posX) * game->deltaDistX;
// 	}
// 	if (game->ray_dirY < 0)
// 	{
// 		game->stepY = -1;
// 		game->sideDistY = (game->posY - game->mapY) * game->deltaDistY;
// 	}
// 	else
// 	{
// 		game->stepY = 1;
// 		game->sideDistY = (game->mapY + 1.0 - game->posY) * game->deltaDistY;
// 	}
// }

// int	perform_dda(t_game *game)
// {
// 	// Perform DDA let's go bitch
// 	while (game->hit == 0)
// 	{
// 	// Jump to next map square, either in x-direction, or in y-direction
// 		if (game->sideDistX < game->sideDistY)
// 		{
// 			game->sideDistX += game->deltaDistX;
// 			game->mapX += game->stepX;
// 			game->side = 0;
// 		}
// 		else
// 		{
// 			game->sideDistY += game->deltaDistY;
// 			game->mapY += game->stepY;
// 			game->side = 1;
// 		}
// 		// Check if ray has hit a wall
// 		if (worldMap[game->mapX][game->mapY] > 0)
// 			game->hit = 1;
// 	}
// 	return (0);
// }

// int	draw_wall(t_game *game)
// {
//     // Calculate distance projected on camera direction (Euclidean 
// 	// distance would give fisheye effect!)
// 	if (game->side == 0) 
// 		game->perpWallDist = (game->mapX - game->posX + (1 - game->stepX) / 2) / game->ray_dirX;
// 	else          
// 		game->perpWallDist = (game->mapY - game->posY + (1 - game->stepY) / 2) / game->ray_dirY;
// 	//calculate height of line to draw on screen
// 	game->lineHeight = (int)(WINDOW_HEIGHT / game->perpWallDist);
// 	//calculate lowest and highest pixel to fill in current stripe
// 	game->drawStart = -(game->lineHeight) / 2 + WINDOW_HEIGHT / 2;
// 	if(game->drawStart < 0)
// 		game->drawStart = 0;
// 	game->drawEnd = game->lineHeight / 2 + WINDOW_HEIGHT / 2;
// 	if(game->drawEnd >= WINDOW_HEIGHT)
// 		game->drawEnd = WINDOW_HEIGHT - 1;
// 	return (0);
// }

// void	find_x_coordinate_in_texture(t_game *game)
// {
// 	extern int	worldMap[24][24];
	
// 	game->tex_x = (int)(game->wall_x * (double)TEX_WIDTH);
// 	if (game->side == 0 && game->ray_dirX > 0)
// 		game->tex_x = TEX_WIDTH - game->tex_x - 1;
// 	if (game->side == 1 && game->ray_dirY < 0)
// 		game->tex_x = TEX_WIDTH - game->tex_x - 1;
// }

// static void	increase_texture_coordinate_perscreen_pixel(t_game *game)
// {
// 	game->step = 1.0 * TEX_HEIGHT / game->lineHeight;
// }

// static void	make_color_darker_for_y_side(t_game *game, int color, int x, int y)
// {
// 	if (game->side == 1)
// 		color = (color >> 1) & 8355711;
// 	game->buf[y][x] = color;
// 	game->re_buf = 1;
// }
// void	get_pixel_color_along_y_axe(t_game *game, int x)
// {
// 	int		y;
// 	int		color;
// 	int		tex_y;
// 	double	texPos;
	
// 	increase_texture_coordinate_perscreen_pixel(game);
// 	texPos = (game->drawStart - WINDOW_HEIGHT / 2 + game->lineHeight / 2) * game->step;
// 	y = game->drawStart;
// 	while (y < game->drawEnd)
// 	{
// 		tex_y = (int)texPos & (TEX_HEIGHT - 1);
// 		texPos += game->step;
// 		color = game->texture[game->tex_number][TEX_HEIGHT * tex_y + game->tex_x];
// 		make_color_darker_for_y_side(game, color, x, y);
// 		y++;
// 	}
// }

// // tex_number --> the value of the current square minus 1. Why minus 1?
// // because there is a texture 0, but map tile 0 has no texture since it
// // represents an empty space.
// // So, to be able to use texture 0 anyway, we substract so that the map
// // tile 1 will have the texture 0, the map tile 2 the texture 1, etc...
// // vall_x --> the exact value where the wall was hit, to just the integer
// // coordonates of the wall. This is required to know wich x-coordinate of the
// // texture we must use. We obtain that value by :
// // 1) Calculate the exact x and y of the world game.
// // 2) Substract off it the integer value of the wall.
// // READ THIS ANTHONY !!!
// // In mathematics and computer science, the 'floor' function is the function
// // that takes as input a real number x, and gives as output the greatest integer
// // less than or equal to x.
// void	choose_wall_texture(t_game *game, int x)
// {
// 	extern int	worldMap[24][24];
	
// 	game->tex_number = worldMap[game->mapX][game->mapY] - 1;
// 	if (game->side == 0)
// 		game->wall_x = game->posY + game->perpWallDist * game->ray_dirY;
// 	else
// 		game->wall_x = game->posX + game->perpWallDist * game->ray_dirX;
// 	game->wall_x -= floor(game->wall_x);
// 	find_x_coordinate_in_texture(game);
// 	get_pixel_color_along_y_axe(game, x);
// }

// void	ray_casting_loop(t_game *game)
// {
// 	int	x;

// 	x = 0;
// 	init_re_buf(game);
// 	while (x < WINDOW_WIDTH)
// 	{
// 		calculate_ray_position_and_direction(game, x);
// 		game->hit = 0;
// 		calculate_step(game);
// 		perform_dda(game);
// 		draw_wall(game);
// 		choose_wall_texture(game, x);
// 		x++;
// 	}
// 	draw_vertical_line(game);
// 	mlx_put_image_to_window(game->mlx, game->win, game->img.mlx_img, 0, 0);
// }

// int	key_hook(int key, t_game *game)
// {
// 	if (key == K_W)
// 	{
// 		if (!worldMap[(int)(game->posX + game->dirX * MOVESPEED)][(int)(game->posY)])
// 			game->posX += game->dirX * MOVESPEED;
// 		if (!worldMap[(int)(game->posX)][(int)(game->posY + game->dirY * MOVESPEED)])
// 			game->posY += game->dirY * MOVESPEED;
// 	}
// 	//move backwards if no wall behind you
// 	if (key == K_S)
// 	{
// 		if (!worldMap[(int)(game->posX - game->dirX * MOVESPEED)][(int)(game->posY)])
// 			game->posX -= game->dirX * MOVESPEED;
// 		if (!worldMap[(int)(game->posX)][(int)(game->posY - game->dirY * MOVESPEED)])
// 			game->posY -= game->dirY * MOVESPEED;
// 	}
// 	//rotate to the right
// 	if (key == K_D)
// 	{
// 		//both camera direction and camera plane must be rotated
// 		double oldDirX = game->dirX;
// 		game->dirX = game->dirX * cos(-ROTSPEED) - game->dirY * sin(-ROTSPEED);
// 		game->dirY = oldDirX * sin(-ROTSPEED) + game->dirY * cos(-ROTSPEED);
// 		double oldPlaneX = game->planeX;
// 		game->planeX = game->planeX * cos(-ROTSPEED) - game->planeY * sin(-ROTSPEED);
// 		game->planeY = oldPlaneX * sin(-ROTSPEED) + game->planeY * cos(-ROTSPEED);
// 	}
// 	//rotate to the left
// 	if (key == K_A)
// 	{
// 		//both camera direction and camera plane must be rotated
// 		double oldDirX = game->dirX;
// 		game->dirX = game->dirX * cos(ROTSPEED) - game->dirY * sin(ROTSPEED);
// 		game->dirY = oldDirX * sin(ROTSPEED) + game->dirY * cos(ROTSPEED);
// 		double oldPlaneX = game->planeX;
// 		game->planeX = game->planeX * cos(ROTSPEED) - game->planeY * sin(ROTSPEED);
// 		game->planeY = oldPlaneX * sin(ROTSPEED) + game->planeY * cos(ROTSPEED);
// 	}
// 	if (key == ESC)
// 		exit(0);
// 	mlx_clear_window(game->mlx, game->win);
// 	ray_casting_loop(game);
// 	return (0);
// }

// static void	fill_buf_with_zeros(t_game *game)
// {
// 	int i;
// 	int	j;
	
// 	i = 0;
// 	while (i < WINDOW_HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WINDOW_WIDTH)
// 		{
// 			game->buf[i][j] = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	init_buf(t_game *game)
// {
// 	int	i;
	
// 	game->buf = (int **)malloc(sizeof(int *) * WINDOW_HEIGHT);
// 	i = 0;
// 	while (i < WINDOW_HEIGHT)
// 	{
// 		game->buf[i] = (int *)malloc(sizeof(int) * WINDOW_WIDTH);
// 		if (!game->buf[i])
// 			return (-2);
// 		i++;
// 	}
// 	fill_buf_with_zeros(game);
// 	return (0);
// }

// void	init_texture(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < 8)
// 	{
// 		j = 0;
// 		while (j < TEX_HEIGHT * TEX_WIDTH)
// 		{
// 			game->texture[i][j] = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// }


// // Double loop that goes through every pixel of the textures, and then the 
// // corresponding pixel of each texture gets a certain value calculated out
// // of x and y. Some textures get a XOR pattern, some a simple gradient, 
// // others a sort of brick pattern.
// void	generate_textures(t_game *game)
// {
// 	int	x;
// 	int y;

// 	x = 0;
// 	while (x < TEX_WIDTH)
// 	{
// 		y = 0;
// 		while (y < TEX_HEIGHT)
// 		{
// 			game->xorcolor = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
// 			game->ycolor = y * 256 / TEX_HEIGHT;
// 			game->xycolor = y * 128 / TEX_HEIGHT + x * 128 / TEX_WIDTH;
// 			game->texture[0][TEX_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEX_WIDTH - y); //flat red texture with black cross
// 			game->texture[1][TEX_WIDTH * y + x] = game->xycolor + 256 * game->xycolor + 65536 * game->xycolor; //sloped greyscale
// 			game->texture[2][TEX_WIDTH * y + x] = 256 * game->xycolor + 65536 * game->xycolor; //sloped yellow gradient
// 			game->texture[3][TEX_WIDTH * y + x] = game->xorcolor + 256 * game->xorcolor + 65536 * game->xorcolor; //xor greyscale
// 			game->texture[4][TEX_WIDTH * y + x] = 256 * game->xorcolor; //xor green
// 			game->texture[5][TEX_WIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
// 			game->texture[6][TEX_WIDTH * y + x] = 65536 * game->ycolor; //red gradient
// 			game->texture[7][TEX_WIDTH * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
// 			y++;
// 		}
// 		x++;
// 	}
// }

// int	init_struct(t_game *game)
// {
// 	game->posX = 22.0;
// 	game->posY = 11.5;
// 	game->dirX = -1.0;
// 	game->dirY = 0.0;
// 	game->planeX = 0.0;
// 	game->planeY = 0.66;
// 	game->re_buf = 0;
// 	return (0);
// }

// int	start_game(t_game *game)
// {
// 	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx");
// 	game->img.mlx_img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	game->img.data = (int *)mlx_get_data_addr(game->img.mlx_img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
// 	ray_casting_loop(game);
// 	mlx_key_hook(game->win, &key_hook, game);
// 	mlx_loop(game->mlx);
// }

// int	init_game(t_game *game)
// {
// 	game->mlx = mlx_init();

// 	init_struct(game);
// 	init_buf(game);
// 	init_texture(game);
// 	generate_textures(game);
// 	start_game(game);
// }

// int	main(void)
// {
// 	t_game game;
// 	init_game(&game);
// 	return (0);
// }
	