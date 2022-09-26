/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_rgb_rm_space_end.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:44:54 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/22 10:48:24 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_rgb_rm_space_end(char **rgb_lst)
{
	int	i;

	i = 0;
	while (rgb_lst[i])
	{
		settings_rm_space_end(rgb_lst[i]);
		i++;
	}
}
