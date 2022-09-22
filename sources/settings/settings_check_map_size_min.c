/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_check_map_size_min.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:31:25 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/22 17:06:01 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_check_map_size_min(t_settings *settings)
{
	int	size;

	size = settings->map_end_line_no - settings->map_start_line_no + 1;
	if (size < MAP_SIZE_MIN)
		return (ft_panic(-1, __func__, ERR_MAP_SIZE_MIN));
	else
	{
		settings->map_height = size;
		return (0);
	}
}
