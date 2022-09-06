/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:56:21 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/06 13:14:13 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	draw_wall(t_vector *vec)
{
    // Calculate distance projected on camera direction (Euclidean 
	// distance would give fisheye effect!)
	vec->h = SCREEN_HEIGHT;
	if (vec->side == 0)
		vec->perp_wall_dist = (vec->side_distX - vec->delta_distX);
	else
		vec->perp_wall_dist = (vec->side_distY - vec->delta_distY);
	// Calculate height of line to draw on screen
	vec->line_height = (int)(vec->h / vec->perp_wall_dist);
	// Calculate lowest and highest pixel to fill in current stripe
	vec->draw_start = -vec->line_height / 2 + vec->h / 2;
	if (vec->draw_start < 0)
		vec->draw_start = 0;
	vec->draw_end = vec->line_height / 2 + vec->h / 2;
	if (vec->draw_end >= vec->h)
		vec->draw_end = vec->h - 1;
	return (0);
}

