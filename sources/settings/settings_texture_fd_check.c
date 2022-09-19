/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_texture_fd_check.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:56:07 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/19 18:22:56 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_texture_fd_check(t_mlx *mlx, char *text_type)
{
	t_settings	*settings;
	int			res;

	settings = &mlx->settings;
	res = 0;
	if (ft_strcmp(text_type, MAP_TEXT_NO) == 0
		&& settings->fd_no != FD_NOT_INIT)
		res = EXIT_FAILURE;
	else if (ft_strcmp(text_type, MAP_TEXT_SO) == 0
		&& settings->fd_so != FD_NOT_INIT)
		res = EXIT_FAILURE;
	else if (ft_strcmp(text_type, MAP_TEXT_WE) == 0
		&& settings->fd_we != FD_NOT_INIT)
		res = EXIT_FAILURE;
	else if (ft_strcmp(text_type, MAP_TEXT_EA) == 0
		&& settings->fd_ea != FD_NOT_INIT)
		res = EXIT_FAILURE;
	if (res)
		ft_panic(-1, __func__, ERR_MAP_DUP_TEXT);
	return (res);
}
