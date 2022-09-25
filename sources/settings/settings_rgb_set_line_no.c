/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb_set_line_no.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:47:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 18:27:47 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_rgb_set_line_no(t_game *game, int txt_type, t_map_fd *map)
{
	t_settings	*settings;

	settings = &game->settings;
	if (txt_type == F)
		settings->f_line_no = map->line_no;
	else if (txt_type == C)
		settings->c_line_no = map->line_no;
}
