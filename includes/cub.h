/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:46:14 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/22 16:04:48 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

//# include "mlx.h"
# include "../minilibX/libmlx.h"
# include "libft.h"

#define X_EVENT_key_hook 2
#define X_EVENT_KEY_EXIT 17
#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define MOVESPEED 0.5
#define ROTSPEED 0.5

/* COLORS */
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x008000
# define BLACK 0x000000
# define BLUE 0xB0E0E6
# define VIOLET 0xC014BC
# define COLOR	0x0FAE4
/* MLX KEY EVENTS */
#  define K_W 119
#  define K_A 97
#  define K_S 115
#  define K_D 100
#  define K_P 112
#  define K_UP 65362 // Ici
#  define K_LEFT 65361
#  define K_DOWN 65364
#  define K_RIGHT 65363 // Ici
#  define K_SHIFT 65505
#  define ESC 65307
// #  define ESP 32

# define BACKGROUND_COLOR 0x00898c83
# define PLAYER_COLOR 0x00a44620

# define FILE_ERROR -1
# define MALLOC_ERROR -2
# define EMPTY_LINE -3

# define SPRITE_COUNT 9
# define CHAR_NOT_FOUND	'N'

#define X_EVENT_KEY_PRESS 17

typedef struct s_sprite
{
	void	*image;
	char	*name;
}	t_sprite;

typedef	struct s_img
{
	int		*data;
	char	*path;
	int		len_path;
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	// int		width;
	// int		height;
} t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		*map;
	double 	posX;
	double	posY; 
	double 	dirX;
	double	dirY; 
	double 	planeX;
	double	planeY;
	double	ray_dirX;
	double	ray_dirY;
	double	cameraX;
	int 	stepX;
	int 	stepY;
	int 	hit;
	int 	side;
	int 	lineHeight;
	double 	sideDistX;
	double 	sideDistY;
	double 	deltaDistX;
	double 	deltaDistY;
	double 	perpWallDist;
	double 	oldDirX;
	double 	oldPlaneX;
	int 	mapX;
	double 	height;
	double 	width;
	int 	mapY;
	int 	drawStart;
	int 	drawEnd;
	int 	color;
	int		**buf;
	int		re_buf;
	int		texture[8][TEX_HEIGHT * TEX_WIDTH];
	int		xorcolor;
	int		ycolor;
	int		xycolor;
	int		tex_number;
	double	wall_x;
	int		tex_x;
	double	step;
} t_game;

typedef struct s_coord
{
	int	x;
	int	y;
	int	draw_loc_x;
	int	draw_loc_y;
}	t_coord;

typedef struct s_palette
{
	int	color_wall;
}	t_palette;


// PARSING
t_list	*create_list(char *line);
t_list	*ft_parse(char *argv);
t_list	*read_map(char *argv);

// GRAPHICS
// void	destroy_sprites(t_game *game);
int		choose_wall_color(t_game *game);
void	draw_vertical_line(t_game *game);
void	free_mlx(t_game *game);
int		key_hook(int keycode, t_game *game);
int		ft_redcross(t_game *game, int x);
int		init_game(t_game *game);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

// CAMERA_MOVEMENTS
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

//TEXTURES
int		init_buf(t_game *game);
void	init_texture(t_game *game);
void	generate_textures(t_game *game);
void	choose_wall_texture(t_game *game, int x);
void	init_re_buf(t_game *game);

// RAY_CASTING
void	calculate_step(t_game *game);
int		calculate_ray_position_and_direction(t_game *game, int x);
int		draw_wall(t_game *game);
int		perform_dda(t_game *game);
int		init_struct(t_game *game);
int		start_ray_casting_loop(t_game *game);

// UTILS
char	get_character_in_map(t_list *map, int x, int y);
void	print_map(t_list *map);

#endif