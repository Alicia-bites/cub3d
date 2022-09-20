/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mlx_show_settings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:51:47 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/07 22:19:35 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cb_mlx_show_settings(t_settings *settings)
{
	cb_mlx_show_string("NO",settings->no);
	cb_mlx_show_string("SO", settings->so);
	cb_mlx_show_string("WE", settings->we);
	cb_mlx_show_string("EA", settings->ea);
	cb_mlx_show_string("FLOOR", settings->floor);
	cb_mlx_show_string("CEIL", settings->ceil);
	printf("floor | g: %d\tg: %d\tb: %d\n", settings->f_r, settings->f_g,
		settings->f_b);
	printf("ceil | g: %d\tg: %d\tb: %d\n", settings->c_r, settings->c_g,
		settings->c_b);
	printf("fd | no: %d\tso: %d\twe: %d\tea: %d\n", settings->fd_no,
		settings->fd_so, settings->fd_we, settings->fd_ea);
	printf("fd | floor: %d\tceil: %d\n", settings->fd_floor,
		settings->fd_ceil);
}
