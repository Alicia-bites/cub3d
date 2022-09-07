/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray_position_and_direction.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:10:33 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/07 11:53:29 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	calculate_ray_position_and_direction(t_vector *vec, int x)
{
	// calculate ray position and direction
	vec->cameraX = 2.0 * (double)x / (double)vec->screen_width - 1.0; // x-coordinate in camera space
	vec->ray_dirX = vec->dirX + vec->planeX * vec->cameraX;
	vec->ray_dirY = vec->dirY + vec->planeY * vec->cameraX;
	//which box of the map we're in
	vec->mapX = (int)vec->posX;
	vec->mapY = (int)vec->posY;
	//length of ray from one x-side to next x-side
	if (vec->ray_dirX == 0.0)
		vec->delta_distX = 1e30;
	else
		vec->delta_distX = fabs(1 / vec->ray_dirX);
	//length of ray from one y-side to next y-side
	if (vec->ray_dirY == 0.0)
		vec->delta_distY = 1e30;
	else
		vec->delta_distY = fabs(1 / vec->ray_dirY);		
		//--> to see if a wall was hit :
	vec->hit = 0;
	return (0);
}
