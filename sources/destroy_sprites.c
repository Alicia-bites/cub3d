/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:14:00 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/01 15:05:08 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	destroy_sprites(t_mlx *mlx)
{
	int	i;

	if (mlx)
	{
		i = 0;
		while (i <= 8)
			mlx_destroy_image(mlx->mlx_ptr, mlx->sprites[i++].image);
	}
}
