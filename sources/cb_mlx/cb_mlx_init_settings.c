/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mlx_init_settings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:34:02 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/20 17:31:31 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cb_mlx_init_settings(t_settings *settings)
{
	settings->no = NULL;
	settings->so = NULL;
	settings->we = NULL;
	settings->ea = NULL;
	settings->floor = NULL;
	settings->f_r = 0;
	settings->f_g = 0;
	settings->f_b = 0;
	settings->ceil = NULL;
	settings->c_r = 0;
	settings->c_g = 0;
	settings->c_b = 0;
	settings->fd_no = FD_NOT_INIT;
	settings->fd_so = FD_NOT_INIT;
	settings->fd_we = FD_NOT_INIT;
	settings->fd_ea = FD_NOT_INIT;
	settings->fd_floor = FD_NOT_INIT;
	settings->fd_ceil = FD_NOT_INIT;
	settings->map_start_line = -1;
}
