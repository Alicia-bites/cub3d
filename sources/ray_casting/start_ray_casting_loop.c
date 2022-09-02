/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ray_casting_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:09:25 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/02 18:09:42 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	start_ray_casting_loop(t_list map)
{
	int			x;
	t_vector	vec;

	set_vectors(&vec);
	x = 0;
	while (x < vec.screen_width)
	{
		calculate_ray_position_and_direction(&vec);
		calculate_step(&vec);
		perform_dda(&vec, map);
	}
	return (0);
}
