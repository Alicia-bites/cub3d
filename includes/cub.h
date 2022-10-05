/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:46:14 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/05 15:43:37 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# include "../minilibX/libmlx.h"
# include "libft.h"
# include "colors.h"

# define SP -1
# define N -2
# define E -3
# define S -4
# define O -5

# define EVENT_KEY_HOOK 2
# define EVENT_KEY_EXIT 17
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define WINDOW_WIDTH 1350
# define WINDOW_HEIGHT 1080
# define MOVESPEED 0.2
# define ROTSPEED 0.2

/* COLORS */
# define FLOOR_COLOR 0x001A5557
# define CEILING_COLOR 0x0000A7B2

/* MLX KEY EVENTS */
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_P 112
# define K_UP 65362
# define K_LEFT 65361
# define K_DOWN 65364
# define K_RIGHT 65363
# define K_SHIFT 65505
# define ESC 65307

/* ERRORS */
# define FILE_ERROR -1
# define MALLOC_ERROR -2
# define EMPTY_LINE -3
# define NO_ADDRESS -4

# define SPRITE_COUNT 9
# define CHAR_NOT_FOUND	'N'

// MAP FILE SETTINGS
# define FD_NOT_INIT -99999999
# define MAP_FORMAT ".cub"
# define MAP_CHARSET "01NSEW "
# define MAP_COLOR_SEP ','
# define MAP_TEXT_FORMAT ".xpm"
# define MAP_TEXT_NO "NO"
# define MAP_TEXT_SO "SO"
# define MAP_TEXT_WE "WE"
# define MAP_TEXT_EA "EA"
# define MAP_TEXT_F "F"
# define MAP_TEXT_C "C"
# define MAP_FILE_MIN_LINE 9
# define MAP_SIZE_MIN 3
# define PLAYER_SP_CHARSET "NSEW"

// MESSAGES
# define ERR_MAP_CHAR "Forbidden char. Expected charset \"01NSEW \""
# define ERR_MAP_CLOSURE "Map is not enclose by wall"
# define ERR_MAP_COLOR_CHAR "Forbidden char. Expected numeric value 0-255"
# define ERR_MAP_COLOR_DEF "Wrong rgb definition. Expected 3 values 0-255"
# define ERR_MAP_COLOR_VAL "Wrong color value. Expected numeric value 0-255"
# define ERR_MAP_CONTENT "No valid map definition. Expected minimum 8 line"
# define ERR_MAP_DUP_TEXT "Duplicate texture in the map file. Expected only one"
# define ERR_MAP_FORMAT "Wrong map format. Expected \".cub\""
# define ERR_MAP_NONE "No map definition, Expected minimum 3 map line"
# define ERR_MAP_ORDER "Wrong map order. Expected map at the end"
# define ERR_MAP_PLAYER_SP "No player spawn. Expected only one N,S,E or W"
# define ERR_MAP_PLAYER_DUP "Expected only one player spawn. N,S,E or W"
# define ERR_MAP_SIZE_MIN "Invalid map size. Expected minimum 3 map line"
# define ERR_MAP_SPACE_IN "Space line in between map definition. Expected none"
# define ERR_MAP_TXT_TYPE "One of texture or rgb value is not correct"
# define ERR_MAP_TXT_FORMAT "Wrong texture format. Expected \".xpm\""

/* MAP FILE SETTINGS
 * char *no,so,we,ea are texture path
 * int *_r/g/b are individual integer value of rgb "255","30","0"
 */
enum e_texture_type
{
	NONE,
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	MAP
};

typedef struct s_settings
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f_r;
	int			f_g;
	int			f_b;
	int			floor;
	int			c_r;
	int			c_g;
	int			c_b;
	int			ceil;
	int			fd_no;
	int			fd_so;
	int			fd_we;
	int			fd_ea;
	int			no_line_no;
	int			so_line_no;
	int			we_line_no;
	int			ea_line_no;
	int			f_line_no;
	int			c_line_no;
	int			map_start_line_no;
	int			map_end_line_no;
	int			map_width;
	int			map_height;
	int			map_player_sp_val;
	int			map_player_sp_x;
	int			map_player_sp_y;
}	t_settings;

typedef struct s_map_fd
{
	int			line_no;
	char		*line;
}	t_map_fd;

typedef struct s_sprite
{
	void		*image;
	char		*name;
}	t_sprite;

typedef struct s_img
{
	void		*img;
	int			*data;
	char		*path;
	int			img_height;
	int			img_width;
	int			len_path;
	void		*mlx_img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img;

typedef struct s_game
{
	int			map_fd;
	t_ulist		**map_fd_lst;
	int			**map_tab;
	t_settings	settings;
	void		*mlx;
	void		*win;
	t_img		img;
	int			*map;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		camera_x;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	double		old_dir_x;
	double		old_plane_x;
	int			map_x;
	int			map_y;
	double		height;
	double		width;
	int			draw_start;
	int			draw_end;
	int			color;
	int			**buf;
	int			re_buf;
	int			**texture;
	int			xorcolor;
	int			ycolor;
	int			xycolor;
	int			tex_number;
	double		wall_x;
	int			tex_x;
	double		step;
	int			tex_dir;
}	t_game;

typedef struct s_palette
{
	int			color_wall;
}	t_palette;

typedef struct s_coord
{
	int			x;
	int			y;
	int			draw_loc_x;
	int			draw_loc_y;
}	t_coord;

// MAIN
int			main_init_conf_game(int argc, char **argv, t_game *game);
void		main_init_map(t_game *game);

// PARSING
int			parse_arg(int argc);
int			parse(int argc, char **argv, t_game *game);
int			parse_map_fd(char *filename, t_game *game);
void		parse_map_fd_free(void *content);
t_map_fd	*parse_map_fd_init(int line_no, char *line);
void		parse_map_fd_show(void *content);
int			parse_map_lst(t_game *game);
int			parse_map_lst_check(t_game *game, int txt_type,
				t_map_fd *map, char *value);
int			parse_map_lst_fullspace(t_game *game, t_ulist *obj);
char		*parse_map_lst_get_value(int txt_type, char *str);
int			parse_map_lst_line(t_game *game, t_ulist *obj);
int			parse_map_lst_line_txt_type(char *line);
void		parse_read_file(t_game *game);

// SETTINGS
int			settings_check(t_settings *settings);
int			settings_check_map_order(t_settings *settings);
int			settings_check_map_start_line(t_settings *settings);
int			settings_check_map_size_min(t_settings *settings);
int			settings_check_txt_type(t_settings *settings);
void		settings_free(t_settings *settings);
void		settings_free_close_fd(int *fd);
void		settings_init(t_settings *settings);
void		settings_init_map(t_settings *settings);
void		settings_init_rgb(t_settings *settings);
int			settings_rgb(t_game *game, int txt_type, char *rgb);
int			settings_rgb_check(char **rgb_lst, int *rgb_tab);
int			settings_rgb_check_char(char *str);
int			settings_rgb_check_dup(t_game *game, int txt_type);
int			settings_rgb_check_space(char *str);
int			settings_rgb_check_value(char *str, int *tab_i);
void		settings_rgb_convert(t_settings *settings);
void		settings_rgb_rm_space_end(char **rgb_lst);
void		settings_rgb_set_line_no(t_game *game, int txt_type, t_map_fd *map);
void		settings_rgb_set_value(t_game *game, int txt_type, int *rgb_tab);
void		settings_rgb_set_value_type(int *r, int *g, int *b, int *rgb_tab);
void		settings_rm_space_end(char *str);
void		settings_show(t_settings *settings);
void		settings_show_string(char *title, char *s);
int			settings_texture_fd_check_dup(t_game *game, int txt_type);
int			settings_texture_fd_open(t_game *game,
				int txt_type, char *filename);
int			settings_texture_fd_save_fd(t_game *game, int txt_type, int fd);
int			settings_texture_fd_save_filename(t_game *game, int txt_type,
				char *filename);
void		settings_texture_fd_set_line_no(t_game *game, int txt_type,
				t_map_fd *map);

// MAP
int			map(t_game *game);
int			map_check(t_game *game, t_ulist *map_obj);
int			map_check_line(t_settings *settings, t_map_fd *map);
int			map_check_line_char(int c);
int			map_check_line_player_sp(t_settings *settings, int c, int x, int y);
void		map_check_width(t_settings *settings, char *str);
t_ulist		*map_get_start_obj(t_game *game);
void		map_rm_nl(t_game *game, t_ulist *map_obj);
void		map_rm_nl_line(char *str);
int			map_tab(t_game *game, t_ulist *map_obj);
void		map_tab_adjust(int **tab);
void		map_tab_adjust_line(int *line);
int			map_tab_check(int **tab, int height, int width);
int			map_tab_check_line(int *line, int *prev, int *next, int width);
int			map_tab_check_line_horizontal(int *line, int i, int dir, int width);
int			map_tab_check_line_vertical(int *line, int i);
int			map_tab_create(t_game *game, t_ulist *map_obj);
int			map_tab_create_line(t_map_fd *map, int *tab, int len_tab);
void		map_tab_free(int **tab);
void		map_tab_init_bzero(int **tab, int len);
int			**map_tab_init(int height, int width);
int			tab_init(t_game *game);
int			*map_tab_init_line(int **tab, int height, int width);
void		map_tab_init_line_bzero(int *line, int width);
int			map_tab_reverse(t_game *game);
void		map_tab_reverse_copy(int **tab_src, int **tab_dest,
				int height, int width);
void		map_tab_reverse_settings(t_settings *settings);
void		map_tab_show(int **tab);

// GRAPHICS
int			choose_wall_color(t_game *game);
void		draw_vertical_line(t_game *game);
int			key_hook(int keycode, t_game *game);
int			ft_redcross(t_game *game, int x);
int			init_game(t_game *game);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			draw_floor(t_game *game);
int			draw_ceiling(t_game *game);
int			draw_background(t_game *game, int x);
int			can_go(t_game *game);

// CAMERA_MOVEMENTS
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_up(t_game *game);
void		rotate_left(t_game *game);
void		rotate_right(t_game *game);

//TEXTURES
int			init_buf(t_game *game);
int			init_texture(t_game *game);
void		generate_textures(t_game *game);
void		choose_wall_texture(t_game *game, int x);
void		init_re_buf(t_game *game);
int			load_texture(t_game *game);

// RAY_CASTING
void		calculate_step(t_game *game);
int			calculate_ray_position_and_direction(t_game *game, int x);
int			calculate_start_and_end_of_line(t_game *game);
int			perform_dda(t_game *game);
int			start_ray_casting_loop(t_game *game);
int			init_struct(t_game *game);
void		init_starting_direction(t_game *game);

// UTILS
char		get_character_in_map(t_list *map, int x, int y);
void		print_map(t_list *map);
int			errors_handler(int err, const char *function_name);
void		clean_up(t_game *game, int err);

// COLORS
void		blue(void);
void		cyan(void);
void		green(void);
void		purple(void);
void		seagreen4(void);
void		reset(void);

//DEBUG
void		print_tab(int **worldMap, int map_width, int map_height);

#endif
