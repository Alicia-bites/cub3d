/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:21:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/22 17:58:03 by abarrier         ###   ########.fr       */
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
	if (map_check_char(mlx, map_obj) != 0)
		return (EXIT_FAILURE);
//	map_rm_space(mlx);
	return (0);
}
