/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_texture_fd_save_fd.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:56:07 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/29 17:32:59 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_texture_fd_save_fd(t_game *game, int txt_type, int fd)
{
	t_settings	*settings;

	settings = &game->settings;
	if (txt_type == NO)
		settings->fd_no = fd;
	else if (txt_type == SO)
		settings->fd_so = fd;
	else if (txt_type == WE)
		settings->fd_we = fd;
	else if (txt_type == EA)
		settings->fd_ea = fd;
	else
		return (EXIT_FAILURE);
	return (0);
}
