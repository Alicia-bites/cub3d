/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_texture_fd_set_line_no.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:56:07 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 18:31:34 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_texture_fd_set_line_no(t_game *game, int txt_type, t_map_fd *map)
{
	t_settings	*settings;

	settings = &game->settings;
	if (txt_type == NO)
		settings->no_line_no = map->line_no;
	else if (txt_type == SO)
		settings->so_line_no = map->line_no;
	else if (txt_type == WE)
		settings->we_line_no = map->line_no;
	else if (txt_type == EA)
		settings->ea_line_no = map->line_no;
}
