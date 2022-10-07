/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:35:57 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/07 10:39:27 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	parse_map_fd_dir(char *filename)
{
	int	fd;

	fd = FD_NOT_INIT;
	fd = open (filename, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		ft_panic(-1, __func__, ERR_MAP_DIR);
		return (EXIT_FAILURE);
	}
	else
		return (0);
}

int	parse_map_fd(char *filename, t_game *game)
{
	int	fd;

	if (ft_formatchr(filename, MAP_FORMAT) == NULL)
		return (ft_panic(-1, __func__, ERR_MAP_FORMAT));
	if (parse_map_fd_dir(filename) != 0)
		return (EXIT_FAILURE);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_panic(-1, __func__, ERR_FILEOPEN));
	else
	{
		game->map_fd = fd;
		return (0);
	}
}
