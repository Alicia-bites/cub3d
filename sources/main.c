/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:54:11 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/01 15:04:44 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

initiate mlx, get map size, inititate game, clean up
int	init_game(t_list *map)
{
	t_mlx	mlx;

	mlx.map = map;
	mlx.win_ptr = NULL;
	mlx.sprites = NULL;
	mlx.sprite_size = 64;
	mlx.map_length = 1280;
	mlx.map_height = 1280;
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (0);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.map_length,
			mlx.map_height, "MAZE");
	// draw_map(map, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, ft_redcross, &mlx);
	mlx_hook(mlx.win_ptr, 2, 1, ft_key_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
	destroy_sprites(&mlx);
	free_mlx(&mlx);
	return (1);
}

int	start_ray_casting_loop(void)
{
	t_mlx	mlx;
	t_vector	vec;

	int	x;

	mlx.map_length = 1280;
	mlx.map_height = 1280;

	vec.posX = 22; // position of the player on the x axe
	vec.posY = 12; // position of the player on the y axe
	vec.dirX = -1;	// initial direction vector
	vec.dirY = 0; // the 2d raycaster version of camera plane
	vec.planeX = 0;
	vec.planeY = 0.66;
	
	vec.time = 0; // time of current frame
	vec.old_time = 0; // time of previous frame
	
	x = 0;
	while (x < mlx.map_length)
	{
	    // calculate ray position and direction
		vec.cameraX = 2 * x / mlx.map_length - 1; // x-coordinate in camera space
		vec.ray_dirX = vec.dirX + vec.planeX * vec.cameraX;
		vec.ray_dirY = vec.dirY + vec.planeY * vec.cameraX;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	// t_list	*map;
	
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Oups, wrong number of arguments!", 2);
		return (-1);
	}
	// map = ft_parse(argv[1]);
	// init_game(map);
	start_ray_casting_loop();
	return (0);
}