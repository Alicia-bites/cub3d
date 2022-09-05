/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:11:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/05 09:53:41 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calculate_step(t_vector *vec)
{
	//calculate step and initial sideDist
	if (vec->ray_dirX < 0)
	{
		vec->stepX = -1;
		vec->side = (vec->posX - vec->mapX) * vec->delta_distX;
	}
	else
	{
		vec->stepX = 1;
		vec->side = (vec->mapX + 1.0 - vec->posX) * vec->delta_distX;
	}
	if (vec->ray_dirY < 0)
	{
		vec->stepY = -1;
		vec->side = (vec->posY - vec->mapY) * vec->delta_distY;
	}
	else
	{
		vec->stepY = 1;
		vec->side = (vec->mapY + 1.0 - vec->posY) * vec->delta_distY;
	}
}
