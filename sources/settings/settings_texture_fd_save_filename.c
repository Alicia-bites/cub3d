/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_texture_fd_save_filename.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:56:07 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/29 17:33:37 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_texture_fd_save_filename(t_game *game, int txt_type,
		char *filename)
{
	t_settings	*settings;

	settings = &game->settings;
	if (txt_type == NO)
		settings->no = filename;
	else if (txt_type == SO)
		settings->so = filename;
	else if (txt_type == WE)
		settings->we = filename;
	else if (txt_type == EA)
		settings->ea = filename;
	else
		return (EXIT_FAILURE);
	return (0);
}
