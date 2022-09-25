/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_show.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:51:47 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 13:32:00 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_show(t_settings *settings)
{
	settings_show_string("NO", settings->no);
	settings_show_string("SO", settings->so);
	settings_show_string("WE", settings->we);
	settings_show_string("EA", settings->ea);
	printf("floor | g: %d\tg: %d\tb: %d\n", settings->f_r, settings->f_g,
		settings->f_b);
	printf("ceil | g: %d\tg: %d\tb: %d\n", settings->c_r, settings->c_g,
		settings->c_b);
	printf("fd | no: %d\tso: %d\twe: %d\tea: %d\n", settings->fd_no,
		settings->fd_so, settings->fd_we, settings->fd_ea);
	printf("line_no | no: %d\tso: %d\twe: %d\tea: %d\tf: %d\tc: %d\n",
		settings->no_line_no, settings->so_line_no,
		settings->we_line_no, settings->ea_line_no,
		settings->f_line_no, settings->c_line_no);
	printf("map | start line: %d\tend line: %d\twidth: %d\theight: %d\n",
		settings->map_start_line_no, settings->map_end_line_no,
		settings->map_width, settings->map_height);
	printf("map player spawn | value: %c\tx: %d\ty: %d\n",
		settings->map_player_sp_val,
		settings->map_player_sp_x, settings->map_player_sp_y);
}
