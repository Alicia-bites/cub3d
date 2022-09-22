/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rm_space_end.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:23:59 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/22 17:59:52 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_rm_space_end(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 0)
		len--;
	while (len > 0 && ft_isspace(str[len]) == 1)
	{
		str[len] = '\0';
		len--;
	}
}
