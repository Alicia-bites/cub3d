/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:09:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/06 12:59:51 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	perform_dda(t_vector *vec, t_list *map)
{
	(void)map;
	// perform DDA
	while (vec->hit == 0)
	{
		// jump to next map square, either in x-direction, or in y-direction
		if (vec->side_distX < vec->side_distY)
		{
			vec->side_distX += vec->delta_distX;
			vec->mapX += vec->stepX;
			vec->side = 0;
		}
		else
		{
			vec->side_distY += vec->delta_distY;
			vec->mapY += vec->stepY;
			vec->side = 1;
		}
		// printf("vec->mapX = %d\n", vec->mapX);
		// printf("vec->mapY = %d\n", vec->mapY);
		// check if ray has hit a wall
		if (get_character_in_map(map, vec->mapX, vec->mapY) == '1')
		{
			// printf("char is = %c\n", get_character_in_map(map, vec->mapX, vec->mapY));
			vec->hit = 1;
		}
	}
	return (0);
}
