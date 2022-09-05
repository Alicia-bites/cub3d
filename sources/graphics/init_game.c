/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:06:50 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/05 19:26:20 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	// start_ray_casting_loop(map);
	mlx_hook(mlx.win_ptr, 17, 0, ft_redcross, &mlx);
	mlx_hook(mlx.win_ptr, 2, 1, ft_key_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
	// destroy_sprites(&mlx);
	free_mlx(&mlx);
	return (1);
}