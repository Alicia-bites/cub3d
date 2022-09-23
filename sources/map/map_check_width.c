/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:06:11 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 13:20:54 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_check_width(t_settings *settings, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if ((int)len >= settings->map_width)
		settings->map_width = (int)len;
}
