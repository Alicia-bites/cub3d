/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_texture_fd_check_dup.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:56:07 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 12:40:06 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_texture_fd_check_dup(t_game *game, int txt_type)
{
	t_settings	*settings;

	settings = &game->settings;
	if (txt_type == NO && settings->fd_no >= 0)
		return (ft_panic(-1, __func__, ERR_MAP_DUP_TEXT));
	else if (txt_type == SO && settings->fd_so >= 0)
		return (ft_panic(-1, __func__, ERR_MAP_DUP_TEXT));
	else if (txt_type == WE && settings->fd_we >= 0)
		return (ft_panic(-1, __func__, ERR_MAP_DUP_TEXT));
	else if (txt_type == EA && settings->fd_ea >= 0)
		return (ft_panic(-1, __func__, ERR_MAP_DUP_TEXT));
	else
		return (0);
}
