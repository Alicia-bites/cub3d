/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:26:46 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/19 10:16:35 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	cb_parse(int argc, char **argv, t_mlx *mlx)
{
	if (cb_parse_arg(argc))
		return (EXIT_FAILURE);
	if (cb_parse_check_file(argv[1], mlx))
		return (EXIT_FAILURE);
	cb_parse_read_file(mlx);
	if (mlx->map_fd_lst == NULL)
		return (EXIT_FAILURE);
	if (ft_lst_size(mlx->map_fd_lst) <= MAP_FILE_MIN_LINE)
		return (EXIT_FAILURE);
	return (0);
}
