/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_wall_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:59:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/06 13:15:33 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	choose_wall_color(t_list *map, t_vector *vec, t_palette *color)
{
	if (get_character_in_map(map, vec->mapX, vec->mapY) == '1')
		color->color_wall = 0x0023466E;
	else if (get_character_in_map(map, vec->mapX, vec->mapY) == '2')
		color->color_wall = 0x00ED6E64;
	else if (get_character_in_map(map, vec->mapX, vec->mapY) == '3')
		color->color_wall = 0x004C9AED;
	else if (get_character_in_map(map, vec->mapX, vec->mapY) == '4')
		color->color_wall = 0x00D6ED34;
	else if (get_character_in_map(map, vec->mapX, vec->mapY) == '5')
		color->color_wall = 0x0092A12B;
	// Give x and y sides different bightness
	if (vec->side == 1)
		color->color_wall = color->color_wall / 2;
	return (0);
}