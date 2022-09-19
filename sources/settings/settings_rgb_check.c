/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:34:58 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/19 17:26:50 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_rgb_check(t_mlx *mlx, char **rgb_tab)
{
	int	i;

	(void)mlx;
	i = 0;
	while (rgb_tab[i])
	{
		if (settings_rgb_check_char(rgb_tab[i]) != 0)
			return (EXIT_FAILURE);
		else if (settings_rgb_check_space(rgb_tab[i]) != 0)
			return (EXIT_FAILURE);
//		else if (settings_rgb_check_value(rgb_tab[i]) != 0)
//			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}
