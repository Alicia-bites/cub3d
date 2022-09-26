/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_check_map_start_line.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:23:59 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/22 16:35:30 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_check_map_start_line(t_settings *settings)
{
	if (settings->map_start_line_no < 0)
		return (ft_panic(-1, __func__, ERR_MAP_NONE));
	else
		return (0);
}
