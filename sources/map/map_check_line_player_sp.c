/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_line_player_sp.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:01:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 11:37:43 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_check_line_player_sp(t_settings *settings, int c, int x, int y)
{
	if (ft_strchr(PLAYER_SP_CHARSET, c) != NULL)
	{
		if (settings->map_player_sp_val < 0)
		{
			settings->map_player_sp_val = c;
			settings->map_player_sp_x = x;
			settings->map_player_sp_y = y;
		}
		else
			return (ft_panic(-1, __func__, ERR_MAP_PLAYER_DUP));
	}
	return (0);
}
