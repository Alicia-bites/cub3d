/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:21:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 18:07:21 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map(t_mlx *mlx)
{
	t_ulist	*map_obj;

	if (!mlx)
		return (ft_panic(-1, __func__, ERR_NOOBJ));
	map_obj = map_get_start_obj(mlx);
	if (!map_obj)
		return (ft_panic(-1, __func__, ERR_NOOBJ));
	map_rm_nl(mlx, map_obj);
	if (map_check(mlx, map_obj) != 0)
		return (EXIT_FAILURE);
	if (map_tab(mlx, map_obj))
		return (EXIT_FAILURE);
	map_tab_show(mlx->map_tab);
	return (0);
}
