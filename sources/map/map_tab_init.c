/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:49:02 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 14:59:28 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	**map_tab_init(t_mlx *mlx)
{
	t_settings	*settings;
	int			i;

	settings = &mlx->settings;
	i = 0;
	mlx->map_tab = (int **)malloc(sizeof(int *) *
			(settings->map_height + 1));
	if (!mlx->map_tab == NULL)
		return (ft_panic(-1, __func__, ERR_MALLOC));
	map_tab_init_bzero(tab, settings->map_height);
	map_tab_init_line(tab, settings->map_height);
	return (0);
}
