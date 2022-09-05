/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_wall_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:59:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/05 19:28:59 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	draw_vertical_line(t_mlx *mlx, t_vector vec, t_palette color)
{
	double	pixels_to_draw;
	t_data	img;
	
	img.img = mlx_new_image(mlx->mlx_ptr, mlx->map_width, mlx->map_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	pixels_to_draw = abs(vec.draw_end - vec.draw_start);
	while (pixels_to_draw)
	{
		my_mlx_pixel_put(&img, );
	}
	
}

int	choose_wall_color(t_vector *vec, t_palette *color);
{
	if (get_character_in_map == '1')
		palette->color_wall = 0x0023466E;
	else if (get_character_in_map == '2')
		palette->color_wall = 0x00ED6E64;
	else if (get_character_in_map == '3')
		palette->color_wall = 0x004C9AED;
	else if (get_character_in_map == '4')
		palette->color_wall = 0x00D6ED34;
	else if (get_character_in_map == '5')
		palette->color_wall = 0x0092A12B;
	// Give x and y sides different bightness
	if (vec->side == 1)
		palette->color_wall /= 2;
}