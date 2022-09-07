/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:46:14 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/07 22:12:03 by abarrier         ###   ########.fr       */
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

# define PI 3.141592653589793238

# define SCREEN_SIZE 1280
# define BACKGROUND_COLOR 0x00898c83
# define PLAYER_COLOR 0x00a44620

# define ESC_KEYCODE 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define CAM_RIGHT 65363
# define CAM_LEFT 65361

# define FILE_ERROR -1
# define MALLOC_ERROR -2
# define EMPTY_LINE -3

# define SPRITE_COUNT 9

// MAP FILE SETTINGS
# define MAP_FORMAT ".cub"
# define MAP_CHARSET "01NSEW "
# define MAP_TEXT_NO "NO"
# define MAP_TEXT_SO "SO"
# define MAP_TEXT_WE "WE"
# define MAP_TEXT_EA "EA"
# define MAP_TEXT_F "F"
# define MAP_TEXT_C "C"
# define FD_NOT_INIT -99999999

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

typedef struct s_sprite
{
	void	*image;
	char	*name;
}	t_sprite;

typedef struct s_mlx
{
	t_list		*map;
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
	double	time;
	double	old_time;
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
	double perpWallDist;
	
}	t_vector;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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
t_list	*create_list(char *line);
t_list	*ft_parse(char *argv);
t_list	*read_map(char *argv);
void	print_map(t_list *map);


// GRAPHICS
// void	destroy_sprites(t_mlx *mlx);
void	draw_player(t_mlx *mlx);
void	draw_background(t_mlx *mlx);
void	draw_no_player(t_mlx *mlx);
void	free_mlx(t_mlx *mlx);
int		ft_key_hook(int keycode, t_mlx *mlx);
int		ft_redcross(t_mlx *mlx, int x);
int		init_game(t_list *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// RAY_CASTING
void	calculate_step(t_vector *vec);
int		calculate_ray_position_and_direction(t_vector *vec, int *x);
int		perform_dda(t_vector *vec, t_list *map);
int		set_vectors(t_vector *vec);
int		start_ray_casting_loop(t_list *map);
#endif
