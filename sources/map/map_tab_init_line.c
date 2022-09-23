/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_init_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:57:06 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/23 15:02:06 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	*map_tab_init_line(int **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		tab[i] = (int *)malloc(sizeof(int) * (len + 1));
		if (!tab[i])
			return (ft_panic_null(-1, __func__, ERR_MALLOC));
		i++;
	}
	tab[i] = NULL;
	return (tab[0]);
}
