/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_check_map_order.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:46:00 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 18:51:50 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_check_map_order(t_settings *settings)
{
	if (settings->no_line_no > settings->map_start_line_no)
		return (ft_panic(-1, __func__, ERR_MAP_ORDER));
	else if (settings->so_line_no > settings->map_start_line_no)
		return (ft_panic(-1, __func__, ERR_MAP_ORDER));
	else if (settings->we_line_no > settings->map_start_line_no)
		return (ft_panic(-1, __func__, ERR_MAP_ORDER));
	else if (settings->ea_line_no > settings->map_start_line_no)
		return (ft_panic(-1, __func__, ERR_MAP_ORDER));
	else if (settings->f_line_no > settings->map_start_line_no)
		return (ft_panic(-1, __func__, ERR_MAP_ORDER));
	else if (settings->c_line_no > settings->map_start_line_no)
		return (ft_panic(-1, __func__, ERR_MAP_ORDER));
	else
		return (0);
}
