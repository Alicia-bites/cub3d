/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_show.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:51:47 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 16:49:18 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_show(t_settings *settings)
{
	settings_show_string("NO", settings->no);
	settings_show_string("SO", settings->so);
	settings_show_string("WE", settings->we);
	settings_show_string("EA", settings->ea);
	settings_show_string("FLOOR", settings->floor);
	settings_show_string("CEIL", settings->ceil);
	printf("floor | g: %d\tg: %d\tb: %d\n", settings->f_r, settings->f_g,
		settings->f_b);
	printf("ceil | g: %d\tg: %d\tb: %d\n", settings->c_r, settings->c_g,
		settings->c_b);
	printf("fd | no: %d\tso: %d\twe: %d\tea: %d\n", settings->fd_no,
		settings->fd_so, settings->fd_we, settings->fd_ea);
	printf("fd | floor: %d\tceil: %d\n", settings->fd_floor,
		settings->fd_ceil);
	printf("map start line: %d\n", settings->map_start_line);
}
