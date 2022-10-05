/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tab_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:49:02 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/05 11:13:19 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	**map_tab_init(int height, int width)
{
	int	**tab;

	tab = NULL;
	tab = (int **)malloc(sizeof(int *) * (height + 1));
	if (tab == NULL)
		return (ft_panic_null(-1, __func__, ERR_MALLOC));
	map_tab_init_bzero(tab, height);
	if (map_tab_init_line(tab, height, width) == NULL)
	{
		map_tab_free(tab);
		return (NULL);
	}
	return (tab);
}
