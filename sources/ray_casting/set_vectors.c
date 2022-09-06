/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:11:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/06 11:37:01 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	set_vectors(t_vector *vec)
{
	vec->screen_width = 1280;
	vec->posX = 22; // position of the player on the x axe
	vec->posY = 12; // position of the player on the y axe
	vec->dirX = -1;	// initial direction vector
	vec->dirY = 0; // the 2d raycaster version of camera plane
	vec->planeX = 0;
	vec->planeY = 0.66;
	return (0);
}
