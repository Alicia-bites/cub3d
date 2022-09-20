/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_texture_fd_check.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:56:07 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/20 10:46:20 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_texture_fd_check(t_mlx *mlx, int txt_type)
{
	t_settings	*settings;
	int			res;

	settings = &mlx->settings;
	res = 0;
	if (txt_type == NO && settings->fd_no != FD_NOT_INIT)
		res = EXIT_FAILURE;
	else if (txt_type == SO && settings->fd_so != FD_NOT_INIT)
		res = EXIT_FAILURE;
	else if (txt_type == WE && settings->fd_we != FD_NOT_INIT)
		res = EXIT_FAILURE;
	else if (txt_type == EA && settings->fd_ea != FD_NOT_INIT)
		res = EXIT_FAILURE;
	if (res)
		ft_panic(-1, __func__, ERR_MAP_DUP_TEXT);
	return (res);
}
