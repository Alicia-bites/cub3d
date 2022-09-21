/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_texture_fd_open.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:35:57 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 12:38:09 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_texture_fd_open(t_mlx *mlx, int txt_type, char *filename)
{
	int	fd;

	if (settings_texture_fd_check_dup(mlx, txt_type) != 0)
		return (EXIT_FAILURE);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_panic(-1, __func__, ERR_FILEOPEN));
	settings_texture_fd_save(mlx, txt_type, fd);
	return (0);
}
