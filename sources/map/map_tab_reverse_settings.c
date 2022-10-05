/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_reverse_settings.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:38:27 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/05 12:25:23 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_tab_reverse_settings(t_settings *settings)
{
	int	tmp_height;
	int	tmp_x;

	tmp_height = settings->map_height;
	settings->map_height = settings->map_width;
	settings->map_width = tmp_height;
	tmp_x = settings->map_player_sp_x;
	settings->map_player_sp_x = settings->map_player_sp_y;
	settings->map_player_sp_y = tmp_x;
}
