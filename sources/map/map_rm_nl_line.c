/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rm_nl_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:23:59 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 10:35:21 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_rm_nl_line(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 0)
		len--;
	str[len] = '\0';
	if (len > 0)
		len--;
	if (len > 0 && str[len] == '\r')
		str[len] = '\0';
}
