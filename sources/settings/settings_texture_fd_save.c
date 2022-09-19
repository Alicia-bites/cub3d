/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_texture_fd_save.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:56:07 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/19 17:32:11 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_texture_fd_save(t_mlx *mlx, char *text_type, int fd)
{
	t_settings	*settings;

	settings = &mlx->settings;
	if (ft_strcmp(text_type, MAP_TEXT_NO) == 0)
		settings->fd_no = fd;
	else if (ft_strcmp(text_type, MAP_TEXT_SO) == 0)
		settings->fd_so = fd;
	else if (ft_strcmp(text_type, MAP_TEXT_WE) == 0)
		settings->fd_we = fd;
	else if (ft_strcmp(text_type, MAP_TEXT_EA) == 0)
		settings->fd_ea = fd;
	else
		return (EXIT_FAILURE);
	return (0);
}
