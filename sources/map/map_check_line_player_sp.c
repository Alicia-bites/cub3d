/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_line_player_sp.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:01:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/28 16:58:12 by abarrier         ###   ########.fr       */
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
			settings->map_player_sp_y = y - settings->map_start_line_no;
		}
		else
			return (ft_panic(-1, __func__, ERR_MAP_PLAYER_DUP));
	}
	return (0);
}
