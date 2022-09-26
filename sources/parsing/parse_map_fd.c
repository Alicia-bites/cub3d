/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:35:57 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/19 17:23:32 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_map_fd(char *filename, t_game *game)
{
	int	fd;

	if (ft_formatchr(filename, MAP_FORMAT) == NULL)
		return (ft_panic(-1, __func__, ERR_MAP_FORMAT));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_panic(-1, __func__, ERR_FILEOPEN));
	else
	{
		game->map_fd = fd;
		return (0);
	}
}
