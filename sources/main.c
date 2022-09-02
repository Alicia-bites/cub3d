/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:54:11 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/02 16:36:51 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	start_ray_casting_loop(void)
{
	int			x;
	t_vector	vec;

	vec.screen_width = 1280;

	vec.posX = 22; // position of the player on the x axe
	vec.posY = 12; // position of the player on the y axe
	vec.dirX = -1;	// initial direction vector
	vec.dirY = 0; // the 2d raycaster version of camera plane
	vec.planeX = 0;
	vec.planeY = 0.66;
	
	vec.time = 0; // time of current frame
	vec.old_time = 0; // time of previous frame
	
	x = 0;
	while (x < vec.screen_width)
	{
	    // calculate ray position and direction
		vec.cameraX = 2 * x / vec.screen_width - 1; // x-coordinate in camera space
		vec.ray_dirX = vec.dirX + vec.planeX * vec.cameraX;
		vec.ray_dirY = vec.dirY + vec.planeY * vec.cameraX;
	}
	return (0);
}


void	draw_background(t_mlx *mlx)
{
	t_coord	pen;
	t_data	img;
	
	pen.draw_loc_x = 0;
	pen.draw_loc_y = 0;
	img.img = mlx_new_image(mlx->mlx_ptr, mlx->map_width, mlx->map_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
		&img.line_length, &img.endian);
	pen.x = 0;
	while (pen.x < mlx->map_width)
	{
		pen.y = 0;
		while (pen.y < mlx->map_height)
		{
			my_mlx_pixel_put(&img, pen.x, pen.y, BACKGROUND_COLOR);
			pen.y++;
		}
		pen.x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img,
		pen.draw_loc_x, pen.draw_loc_y);
}

void	draw_player(t_mlx *mlx)
{
	t_coord	pen;
	t_data	img;
	
	pen.draw_loc_x = 500;
	pen.draw_loc_y = 500;
	img.img = mlx_new_image(mlx->mlx_ptr, 15, 15);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
		&img.line_length, &img.endian);
	pen.x = 0;
	while (pen.x < 15)
	{
		pen.y = 0;
		while (pen.y < 15)
		{
			my_mlx_pixel_put(&img, pen.x, pen.y, PLAYER_COLOR);
			pen.y++;
		}
		pen.x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img,
		pen.draw_loc_x, pen.draw_loc_y);
	mlx->player_x = 500;
	mlx->player_y = 500;
	mlx->player_image = img.img;	
}

void	draw_no_player(t_mlx *mlx)
{
	t_coord	pen;
	t_data	img;
	
	pen.draw_loc_x = 500;
	pen.draw_loc_y = 500;
	img.img = mlx_new_image(mlx->mlx_ptr, 15, 15);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
		&img.line_length, &img.endian);
	pen.x = 0;
	while (pen.x < 15)
	{
		pen.y = 0;
		while (pen.y < 15)
		{
			my_mlx_pixel_put(&img, pen.x, pen.y, BACKGROUND_COLOR);
			pen.y++;
		}
		pen.x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img,
		pen.draw_loc_x, pen.draw_loc_y);
	mlx->player_x = 500;
	mlx->player_y = 500;
	mlx->no_player_image = img.img;	
}

int	init_game(t_list *map)
{
	t_mlx	mlx;

	(void)map;
	// mlx.map = map;
	mlx.win_ptr = NULL;
	// mlx.sprites = NULL;
	mlx.sprite_size = 64;
	mlx.map_width = 1280;
	mlx.map_height = 1280;
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (-2);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.map_width,
			mlx.map_height, "MAZE");
	draw_background(&mlx);
	draw_player(&mlx);
	draw_no_player(&mlx);
	// draw_map(map, &mlx);
	// start_ray_casting_loop();
	mlx_hook(mlx.win_ptr, 17, 0, ft_redcross, &mlx);
	mlx_hook(mlx.win_ptr, 2, 1, ft_key_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
	// destroy_sprites(&mlx);
	free_mlx(&mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*map;
	
	(void)argv;
	if (argc != 2)
	{
		ft_putstr_fd("Oups, wrong number of arguments!", 2);
		return (-1);
	}
	map = NULL;
	init_game(map);
	return (0);
}