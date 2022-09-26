/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lst_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:58:38 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/22 10:16:29 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_map_lst_check(t_game *game, int txt_type, t_map_fd *map,
		char *value)
{
	if (txt_type == NO || txt_type == SO
		|| txt_type == WE || txt_type == EA)
	{
		if (settings_texture_fd_open(game, txt_type, value) != 0)
			return (EXIT_FAILURE);
		settings_texture_fd_set_line_no(game, txt_type, map);
	}
	else if (txt_type == F || txt_type == C)
	{
		if (settings_rgb(game, txt_type, value) != 0)
			return (EXIT_FAILURE);
		settings_rgb_set_line_no(game, txt_type, map);
	}
	else if (txt_type == MAP)
	{
		if (game->settings.map_start_line_no < 0)
			game->settings.map_start_line_no = map->line_no;
		else if (game->settings.map_start_line_no >= 0
			&& game->settings.map_end_line_no >= 0)
			return (ft_panic(-1, __func__, ERR_MAP_ORDER));
	}
	return (0);
}
