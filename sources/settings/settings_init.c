/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:34:02 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 17:40:03 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_init(t_settings *settings)
{
	settings->no = NULL;
	settings->so = NULL;
	settings->we = NULL;
	settings->ea = NULL;
	settings->f_r = -1;
	settings->f_g = -1;
	settings->f_b = -1;
	settings->c_r = -1;
	settings->c_g = -1;
	settings->c_b = -1;
	settings->fd_no = FD_NOT_INIT;
	settings->fd_so = FD_NOT_INIT;
	settings->fd_we = FD_NOT_INIT;
	settings->fd_ea = FD_NOT_INIT;
	settings->no_line_no = -1;
	settings->so_line_no = -1;
	settings->we_line_no = -1;
	settings->ea_line_no = -1;
	settings->f_line_no = -1;
	settings->c_line_no = -1;
	settings_init_map(settings);
}
