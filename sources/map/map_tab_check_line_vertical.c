/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_check_line_vertical.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:48:59 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/24 11:58:35 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_tab_check_line_vertical(int *line, int i)
{
	if (!line || line[i] == ' ')
		return (ft_panic(-1, __func__, ERR_MAP_CLOSURE));
	return (0);
}
