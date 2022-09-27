/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:21:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/27 17:14:23 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map(t_game *game)
{
	t_ulist	*map_obj;

	if (!game)
		return (ft_panic(-1, __func__, ERR_NOOBJ));
	map_obj = map_get_start_obj(game);
	if (!map_obj)
		return (ft_panic(-1, __func__, ERR_NOOBJ));
	map_rm_nl(game, map_obj);
	if (map_check(game, map_obj) != 0)
		return (EXIT_FAILURE);
	if (map_tab(game, map_obj))
		return (EXIT_FAILURE);
	// map_tab_show(game->map_tab);
	return (0);
}
