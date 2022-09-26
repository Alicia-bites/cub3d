/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:26:46 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 09:41:54 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse(int argc, char **argv, t_game *game)
{
	if (parse_arg(argc))
		return (EXIT_FAILURE);
	if (parse_map_fd(argv[1], game) != 0)
		return (EXIT_FAILURE);
	parse_read_file(game);
	close(game->map_fd);
	game->map_fd = FD_NOT_INIT;
	if (game->map_fd_lst == NULL)
		return (EXIT_FAILURE);
	if (ft_lst_size(game->map_fd_lst) < MAP_FILE_MIN_LINE)
		return (ft_panic_value(-1, __func__, ERR_MAP_CONTENT,
				EXIT_FAILURE));
	if (parse_map_lst(game) != 0)
		return (EXIT_FAILURE);
	return (0);
}
