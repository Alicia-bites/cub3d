#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <strings.h>
#include "../../minilibX/libmlx.h"

#define WIDTH 800
#define HEIGHT 600
#define PI 3.141592
#define FOV 2 * atan(0.66/1.0)
#define mapWIDTH 24
#define mapHeight 24
#define screenWIDTH 640
#define screenHeight 480
#define moveSpeed 0.1
#define rotSpeed 0.1

/* COLORS */
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x008000
# define BLACK 0x000000
# define BLUE 0xB0E0E6
# define VIOLET 0xC014BC
# define TEST	0x0FAE4
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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*b;
	size_t			i;

	i = 0;
	b = (unsigned char *)s;
	while (i < n)
	{
		b[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	sizebis;

	sizebis = size * nmemb;
	ptr = malloc(sizebis);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, sizebis);
	return (ptr);
}

int worldMap[mapWIDTH][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef	struct s_imag
{
	char	*path;
	int		len_path;
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
} t_imag;

// typedef struct s_pos
// {
// 	double x;
// 	double y;
// }	t_pos;

// typedef struct s_vector
// {
// 	double x;
// 	double y;
// 	double norm;
// }	t_vector;

typedef struct s_global
{
	void		*mlx;
	void		*win;
	t_imag		*image;
	// t_pos		*pos;
	double 	posX;
	double	posY; 
	double 	dirX;
	double	dirY; 
	double 	planeX;
	double	planeY;
	double	ray_dirX;
	double	ray_dirY;
	// t_vector	*dir;
	// t_vector	*plane;
	// t_vector	*ray;
	double		camX;
	int stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	double oldDirX;
	double oldPlaneX;
	int mapX;
	double height;
	double width;
	int mapY;
	int drawStart;
	int drawEnd;
	int color;
} t_global;

// void	rotation(t_vector *v, double angle)
// {
// 	t_vector old;

// 	old = *v;
// 	v->x = old.x * cos(angle) - old.y * sin(angle);
// 	v->y = old.x * sin(angle) + old.y * cos(angle);
// }

void	put_pixel_to_image(t_imag *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(unsigned int*)dst = color;
}

int	keypress(int key, t_global *test)
{
	printf("pos_x == %f\n", (test->posX));
	if (key == K_UP) // UP
	{
		if(worldMap[(int)(test->posX + test->dirX * moveSpeed)][(int)test->posY] == 0)
			test->posX += test->dirX * moveSpeed;
		if(worldMap[(int)(test->posX)][(int)(test->posY + test->dirY * moveSpeed)] == 0)
			test->posY += test->dirY * moveSpeed;
	}
	if (key == K_DOWN) // DOWN
	{
		if(worldMap[(int)(test->posX - test->dirX * moveSpeed)][(int)test->posY] == 0)
			test->posX -= test->dirX * moveSpeed;
		if(worldMap[(int)(test->posX)][(int)(test->posY - test->dirY * moveSpeed)] == 0)
			test->posY -= test->dirY * moveSpeed;
	}
	if (key == K_RIGHT)
    {
      //both camera direction and camera plane must be rotated
		test->oldDirX = test->dirX;
		test->dirX = test->dirX * cos(-rotSpeed) - test->dirY * sin(-rotSpeed);
		test->dirY = test->oldDirX * sin(-rotSpeed) + test->dirY * cos(-rotSpeed);
		test->oldPlaneX = test->planeX;
		test->planeX = test->planeX * cos(-rotSpeed) - test->planeY * sin(-rotSpeed);
		test->planeY = test->oldPlaneX * sin(-rotSpeed) + test->planeY * cos(-rotSpeed);
    }
	if (key == K_LEFT)
    {
      //both camera direction and camera plane must be rotated
		test->oldDirX = test->dirX;
		test->dirX = test->dirX * cos(rotSpeed) - test->dirY * sin(rotSpeed);
		test->dirY = test->oldDirX * sin(rotSpeed) + test->dirY * cos(rotSpeed);
		test->oldPlaneX = test->planeX;
		test->planeX = test->planeX * cos(rotSpeed) - test->planeY * sin(rotSpeed);
		test->planeY = test->oldPlaneX * sin(rotSpeed) + test->planeY * cos(rotSpeed);
    }	
	return (0);
}

void	clear_window(t_global *glob)
{
	ft_bzero(glob->image->addr, HEIGHT * WIDTH * 4);
}

int	raycasting(t_global *glob)
{	
	int			x;
	clear_window(glob);
	for(x = 0; x < WIDTH; x++)
	{
		glob->camX = 2.0 * (double)x / (double)glob->width - 1.0;
		glob->ray_dirX = glob->dirX + glob->planeX * glob->camX;
		glob->ray_dirY = glob->dirY + glob->planeY * glob->camX;
		glob->mapX = (int)glob->posX;
		glob->mapY = (int)glob->posY;
		glob->hit = 0;
		if (glob->ray_dirX == 0.0)
			glob->deltaDistX = 1e30;
		else
			glob->deltaDistX = fabs(1.0 / glob->ray_dirX);
		if (glob->ray_dirY == 0.0)
			glob->deltaDistY = 1e30;
		else
			glob->deltaDistY = fabs(1.0 / glob->ray_dirY);
		if (glob->ray_dirX < 0)
		{
			glob->stepX = -1;
			glob->sideDistX = (glob->posX - glob->mapX) * glob->deltaDistX;
		}
		else
		{
			glob->stepX = 1;
			glob->sideDistX = (glob->mapX + 1.0 - glob->posX) * glob->deltaDistX;
		}
		if (glob->ray_dirY < 0)
		{
			glob->stepY = -1;
			glob->sideDistY = (glob->posY - glob->mapY) * glob->deltaDistY;
		}
		else
		{
			glob->stepY = 1;
			glob->sideDistY = (glob->mapY + 1.0 - glob->posY) * glob->deltaDistY;
		}
		while (glob->hit == 0)
		{
		//jump to next map square, either in x-direction, or in y-direction
			if (glob->sideDistX < glob->sideDistY)
			{
				glob->sideDistX += glob->deltaDistX;
				glob->mapX += glob->stepX;
				glob->side = 0;
			}
			else
			{
				glob->sideDistY += glob->deltaDistY;
				glob->mapY += glob->stepY;
				glob->side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[glob->mapX][glob->mapY] > 0)
				glob->hit = 1;
		}
		if(glob->side == 0) 
			glob->perpWallDist = (glob->sideDistX - glob->deltaDistX);
		else          
			glob->perpWallDist = (glob->sideDistY - glob->deltaDistY);
		glob->lineHeight = (int)(glob->height / glob->perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		glob->drawStart = -(glob->lineHeight) / 2 + glob->height / 2;
		if(glob->drawStart < 0)
			glob->drawStart = 0;
		glob->drawEnd = glob->lineHeight / 2 + glob->height / 2;
		if(glob->drawEnd >= glob->height)
			glob->drawEnd = glob->height - 1;
		// printf("glob-> == %d -- MAPY == %d -- world glob->_mapY = %d\n", glob->, mapY, worldMap[glob->][mapY]);
		switch(worldMap[glob->mapX][glob->mapY])
		{
			case 1:  glob->color = RED;  break; //red
			case 2:  glob->color = GREEN;  break; //green
			case 3:  glob->color = BLUE;   break; //blue
			case 4:  glob->color = WHITE;  break; //white
			default: glob->color = VIOLET; break; //yellow
		}
		//give x and y sides different brightness
		if (glob->side == 1)
			glob->color = glob->color / 2;
		int y = glob->drawStart;
		while (y < glob->drawEnd)
		{
			put_pixel_to_image(glob->image, x, y, glob->color);
			y++;
		}
		mlx_put_image_to_window(glob->mlx, glob->win, glob->image->mlx_img, 0, 0);
	}
	return (0);
}

void	gaming(t_global *test)
{	
	test->mlx = mlx_init();
	test->win =  mlx_new_window(test->mlx, WIDTH, HEIGHT, "Cub3d");
	test->image->mlx_img = mlx_new_image(test->mlx, WIDTH, HEIGHT);
	test->image->addr = mlx_get_data_addr(test->image->mlx_img, &test->image->bpp, &test->image->line_len, &test->image->endian);
	mlx_key_hook(test->win, keypress, test);
	mlx_loop_hook(test->mlx, raycasting, test);
	mlx_loop(test->mlx);
	mlx_destroy_image(test->mlx, test->image->mlx_img);
	mlx_destroy_window(test->mlx, test->win);
	mlx_destroy_display(test->mlx);
}

t_imag	*init_image(t_imag *image)
{
	image = ft_calloc(1, sizeof(t_imag));
	if (!image)
		return (NULL);
	return (image);
}

void init_struct(t_global *test)
{
	test->image = init_image(test->image);
	test->posX = 22;
	test->posY = 12;
	test->dirX = -1;
	test->dirY = 0;
	test->planeX = 0.0;
	test->planeY = 0.66;
	test->dirX = -1;
	test->dirY = 0;
	test->width = WIDTH;
	test->height = HEIGHT;
	gaming(test);
}

int main(void)
{
	t_global	test;

	init_struct(&test);
	return (0);
}