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

# define PI 3.141592653589793238

# define SCREEN_HEIGHT 1280
# define SCREEN_WIDTH 1280

# define MOVESPEED 0.5
# define ROTSPEED 0.2

# define BACKGROUND_COLOR 0x00898c83
# define PLAYER_COLOR 0x00a44620
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x008000
# define BLACK 0x000000
# define BLUE 0xB0E0E6
# define VIOLET 0xC014BC
# define TEST	0x0FAE4

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
# define CHAR_NOT_FOUND	'N'

#define mapWIDTH 24
#define mapHeight 24

typedef struct s_sprite
{
	void	*image;
	char	*name;
}	t_sprite;

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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	t_list		*map;
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
	t_vector	vec;
	t_data		img;
}	t_mlx;

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

void	start_game(t_mlx *mlx)
{	
	mlx = mlx_init();
	mlx->win_ptr =  mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d");
	mlx->img->img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	test->image->addr = mlx_get_data_addr(test->image->mlx_img, &test->image->bpp, &test->image->line_len, &test->image->endian);
	mlx_key_hook(test->win, keypress, test);
	mlx_loop_hook(test->mlx, raycasting, test);
	mlx_loop(test->mlx);
	mlx_destroy_image(test->mlx, test->image->mlx_img);
	mlx_destroy_window(test->mlx, test->win);
	mlx_destroy_display(test->mlx);
}

void init_struct(t_mlx *mlx)
{
	mlx->vec.screen_width = 1280;
	mlx->vec.posX = 22; // position of the player on the x axe
	mlx->vec.posY = 12; // position of the player on the y axe
	mlx->vec.dirX = -1;	// initial direction mlx->vector
	mlx->vec.dirY = 0; // the 2d raycaster mlx->version of camera plane
	mlx->vec.planeX = 0;
	mlx->vec.planeY = 0.66;
}

int main(void)
{
	t_mlx mlx;

	init_struct(&mlx);
	start_game(&mlx);
	return (0);
}