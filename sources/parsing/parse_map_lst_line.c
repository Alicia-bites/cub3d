/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lst_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:02:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 17:54:58 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_map_lst_line(t_mlx *mlx, t_ulist *obj)
{
	t_map_fd	*map;
	int			txt_type;
	char		*value;

	map = (t_map_fd *)obj->content;
	txt_type = parse_map_lst_line_txt_type(map);
	value = parse_map_lst_get_value(mlx, txt_type, map->line);
	if (!value)
		return (0);
	if (parse_map_lst_check(mlx, txt_type, map, value) != 0)
		return (EXIT_FAILURE);
	return (0);
}
