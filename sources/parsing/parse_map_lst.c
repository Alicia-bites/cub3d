/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:39:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 17:55:13 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_map_lst(t_mlx *mlx)
{
	t_ulist	*obj;
	int		is_fullspace;

	if (!mlx)
		return (ft_panic(-1, __func__, ERR_NOOBJ));
	obj = *mlx->map_fd_lst;
	while (obj)
	{
		is_fullspace = parse_map_lst_fullspace(mlx, obj);
		if (is_fullspace == -1)
			return (EXIT_FAILURE);
		else if (is_fullspace == 0)
		{
			if (parse_map_lst_line(mlx, obj) != 0)
				return (EXIT_FAILURE);
		}
		obj = obj->next;
	}
	return (0);
}
