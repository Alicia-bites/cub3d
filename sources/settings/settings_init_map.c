/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_init_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:00:59 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 17:31:28 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_init_map(t_settings *settings)
{
	settings->map_start_line_no = -1;
	settings->map_end_line_no = -1;
	settings->map_width = -1;
	settings->map_height = -1;
	settings->map_player_sp_val = -1;
	settings->map_player_sp_x = -1;
	settings->map_player_sp_y = -1;
}
