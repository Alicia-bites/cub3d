/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:26:46 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/20 17:08:42 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse(int argc, char **argv, t_mlx *mlx)
{
	if (parse_arg(argc))
		return (EXIT_FAILURE);
	if (parse_map_fd(argv[1], mlx) != 0)
		return (EXIT_FAILURE);
	parse_read_file(mlx);
	close(mlx->map_fd);
	mlx->map_fd = FD_NOT_INIT;
	if (mlx->map_fd_lst == NULL)
		return (EXIT_FAILURE);
	if (ft_lst_size(mlx->map_fd_lst) < MAP_FILE_MIN_LINE)
		return (ft_panic_value(-1, __func__, ERR_MAP_CONTENT,
				EXIT_FAILURE));
//	if (parse_map_lst(mlx) != 0)
//		return (EXIT_FAILURE);
	return (0);
}
