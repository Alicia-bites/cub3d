/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:46:14 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/19 17:33:30 by abarrier         ###   ########.fr       */
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
//# include "libmlx.h"
# include "libft.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define PI 3.141592653589793238
#define FOV 2 * atan(0.66/1.0)
#define mapWIDTH 24
#define mapHeight 24
#define screenWIDTH 1000
#define screenHeight 1000
#define MOVESPEED 0.05
#define ROTSPEED 0.05

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
#  define ESP 32

# define BACKGROUND_COLOR 0x00898c83
# define PLAYER_COLOR 0x00a44620

# define FILE_ERROR -1
# define MALLOC_ERROR -2
# define EMPTY_LINE -3

# define SPRITE_COUNT 9
# define CHAR_NOT_FOUND	'N'

#define mapWIDTH 24
#define mapHeight 24

#define X_EVENT_KEY_PRESS 17

// MAP FILE SETTINGS
# define FD_NOT_INIT -99999999
# define MAP_FORMAT ".cub"
# define MAP_CHARSET "01NSEW "
# define MAP_COLOR_SEP ','
# define MAP_TEXT_NO "NO"
# define MAP_TEXT_SO "SO"
# define MAP_TEXT_WE "WE"
# define MAP_TEXT_EA "EA"
# define MAP_TEXT_F "F"
# define MAP_TEXT_C "C"
# define MAP_FILE_MIN_LINE 8

// MESSAGES
# define ERR_MAP_COLOR_CHAR "Wrong char. Expected numeric value 0-255"
# define ERR_MAP_COLOR_DEF "Wrong color definition. Expected rgb definition"
# define ERR_MAP_COLOR_VAL "Wrong color value. Expected numeric value 0-255"
# define ERR_MAP_DUP_TEXT "Duplicate texture in the map file. Expected only one"
# define ERR_MAP_FORMAT "Wrong map format. Expected \".cub\""

/* MAP FILE SETTINGS
 * char *no,so,we,ea are texture path
 * char *floor, cell are full string of rgb value as "255,30,0"
 * int *_r/g/b are individual integer value of rgb "255","30","0"
 */
typedef struct s_settings
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*floor;
	int	f_r;
	int	f_g;
	int	f_b;
	char	*ceil;
	int	c_r;
	int	c_g;
	int	c_b;
	int	fd_no;
	int	fd_so;
	int	fd_we;
	int	fd_ea;
	int	fd_floor;
	int	fd_ceil;
}	t_settings;

typedef struct s_map_fd
{
	int	line_no;
	char	*line;
}	t_map_fd;

typedef struct s_sprite
{
	void	*image;
	char	*name;
}	t_sprite;

typedef struct s_mlx
{
	t_list		*map;
	int		map_fd;
	t_ulist		**map_fd_lst;
	t_settings	settings;
	int			image_height;
	int			image_width;
	int			row_width;
	int			col_height;
	int			map_height;
	int			map_width;
	int			sprite_size;
	int			player_x;
	int			player_y;
	void		*image;
	void		*mlx_ptr;
	void		*player;
	void		*win_ptr;
	void		*player_image;
	void		*no_player_image;
}	t_mlx;

typedef	struct s_vector
{
	double 	posX;
	double	posY; 
	double 	dirX;
	double	dirY; 
	double 	planeX;
	double	planeY;
	double	cameraX;
	double	ray_dirX;
	double	ray_dirY;
	double	screen_width;
	int		mapX;
	int		mapY;

	double	delta_distX;
	double	delta_distY;
	//length of ray from current position to next x or y-side
	double 	side_distX;
	double 	side_distY;
	//what direction to step in x or y-direction (either +1 or -1)
	int 	stepX;
	int 	stepY;
	int		hit;
	//was a NS or a EW wall hit?
	int		side;
	
	//used to calculate the length of the ray
	double perp_wall_dist;

	int		line_height;
	int		draw_start;
	int		draw_end;
	int		h;
	double	old_dirX;
	double	old_planeX;
	
}	t_vector;

typedef	struct s_img
{
	char	*path;
	int		len_path;
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
} t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	*image;
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
} t_game;

typedef struct s_coord
{
	int	x;
	int	y;
	int	draw_loc_x;
	int	draw_loc_y;
}	t_coord;

//MLX
void	cb_mlx_init(t_mlx *mlx);
void	cb_mlx_init_settings(t_settings *settings);
void	cb_mlx_show(t_mlx *mlx);
void	cb_mlx_show_settings(t_settings *settings);
void	cb_mlx_show_string(char *title, char *s);


//PARSING
typedef struct s_palette
{
	int	color_wall;
}	t_palette;


// PARSING
int     parse_arg(int argc);
int     parse(int argc, char **argv, t_mlx *mlx);
int     parse_map_fd(char *filename, t_mlx *mlx);
void	parse_map_fd_free(void *content);
t_map_fd   *parse_map_fd_init(int line_no, char *line);
void    parse_map_fd_show(void *content);
void    parse_read_file(t_mlx *mlx);

t_list	*create_list(char *line);
t_list	*ft_parse(char *argv);
t_list	*read_map(char *argv);

// SETTINGS
int     settings_rgb(t_mlx *mlx, char *rgb);
int     settings_rgb_check(t_mlx *mlx, char **rgb_tab);
int     settings_rgb_check_char(char *str);
int     settings_rgb_check_space(char *str);
int     settings_rgb_check_value(char *str);
int     settings_texture_fd_check(t_mlx *mlx, char *text_type);
int     settings_texture_fd_open(t_mlx *mlx, char *text_type, char *filename);
int     settings_texture_fd_save(t_mlx *mlx, char *text_type, int fd);

// GRAPHICS
// void	destroy_sprites(t_game *game);
int		choose_wall_color(t_game *game);
int		draw_vertical_line(t_game *game, int x);
void	free_mlx(t_game *game);
int		ft_key_hook(int keycode, t_game *game);
int		keypress(int keycode, t_game *game);
int		ft_redcross(t_game *game, int x);
int		init_game(t_game *game);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

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
