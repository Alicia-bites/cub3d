/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:03:10 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 15:05:37 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_tab_free(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (!mlx->map_tab)
		return ;
	while (mlx->map_tab[i])
	{
		if (mlx->map_tab[i])
		{
			free(mlx->map_tab[i]);
			mlx->map_tab[i] = NULL;
		}
		i++;
	}
}
