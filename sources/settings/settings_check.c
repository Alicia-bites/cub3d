/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:36:24 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/22 17:04:55 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_check(t_settings *settings)
{
	if (settings_check_txt_type(settings) != 0)
		return (EXIT_FAILURE);
	if (settings_check_map_start_line(settings) != 0)
		return (EXIT_FAILURE);
	if (settings_check_map_size_min(settings) != 0)
		return (EXIT_FAILURE);
	if (settings_check_map_order(settings) != 0)
		return (EXIT_FAILURE);
	return (0);
}
