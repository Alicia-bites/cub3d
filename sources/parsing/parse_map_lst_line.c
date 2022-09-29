/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_lst_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:02:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/29 11:46:40 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_map_lst_line(t_game *game, t_ulist *obj)
{
	t_map_fd	*map;
	int			txt_type;
	char		*value;
	int			i;

	map = (t_map_fd *)obj->content;
	i = 0;
	while (ft_isspace(map->line[i]) == 1)
		i++;
	txt_type = parse_map_lst_line_txt_type(&map->line[i]);
	value = parse_map_lst_get_value(txt_type, &map->line[i]);
	if (!value)
		return (0);
	if (parse_map_lst_check(game, txt_type, map, value) != 0)
		return (EXIT_FAILURE);
	if (obj->next == NULL && game->settings.map_end_line_no < 0)
		game->settings.map_end_line_no = map->line_no;
	return (0);
}
