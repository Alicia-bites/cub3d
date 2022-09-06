/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 09:36:25 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/06 13:16:34 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	draw_vertical_line(int x, t_vector vec, int color, t_data *img)
{
	int		y;

	y = vec.draw_start;
	while (y < vec.draw_end)
	{
		my_mlx_pixel_put(img, x, y, color / 2);
		y++;
	}
	return (0);
}
