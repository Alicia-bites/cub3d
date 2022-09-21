/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:39:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 09:45:07 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_map_lst(t_mlx *mlx)
{
	t_ulist	*obj;
	if (!mlx)
		return (ft_panic(-1, __func__, ERR_NOOBJ));
	obj = *mlx->map_fd_lst;
	while (obj)
	{
		t_map_fd *map = (t_map_fd *)obj->content;
		if (parse_map_lst_fullspace(mlx, obj) == -1)
			return (EXIT_FAILURE);
		else if (parse_map_lst_fullspace(mlx, obj) == 0)
		{
			printf("DEBUG: [%d] is a line\n", map->line_no); 
//			if (parse_map_lst_line(mlx, obj) == -1)
//				return (EXIT_FAILURE);
		}
		else
			printf("DEBUG: [%d] fullspace line\n", map->line_no); 
		obj = obj->next;
	}
	return (0);
}
