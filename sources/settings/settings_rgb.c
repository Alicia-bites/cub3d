/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:18:26 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/19 17:26:23 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_rgb(t_mlx *mlx, char *rgb)
{
	char	**rgb_tab;

	rgb_tab = NULL;
	if (ft_strnchar(rgb, MAP_COLOR_SEP) != 2)
		return (ft_panic(-1, __func__, ERR_MAP_COLOR_DEF));
	rgb_tab = ft_split((const char *)rgb, MAP_COLOR_SEP);
	if (!rgb_tab)
		return (ft_panic(-1, __func__, ERR_NOOBJ));
	if (settings_rgb_check(mlx, rgb_tab) != 0)
	{
		ft_free_ptrptr_str(rgb_tab);
		return (EXIT_FAILURE);
	}
	ft_free_ptrptr_str(rgb_tab);
	return (0);
}
