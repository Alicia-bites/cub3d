/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ray_casting_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:09:25 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/05 19:28:45 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	start_ray_casting_loop(t_list *map, t_mlx *mlx)
{
	int			x;
	t_vector	vec;
	t_palette	color;

	set_vectors(&vec);
	x = 0;
	while (x < vec.screen_width)
	{
		calculate_ray_position_and_direction(&vec, &x);
		calculate_step(&vec);
		perform_dda(&vec, map);
		draw_wall(&vec);
		choose_wall_color(&vec, &color);
		draw_vertical_line(mlx, vec, color);
		x++;
	}
	return (0);
}
