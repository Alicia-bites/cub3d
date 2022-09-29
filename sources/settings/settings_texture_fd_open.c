/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_texture_fd_open.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:35:57 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/29 17:35:43 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_texture_fd_open(t_game *game, int txt_type, char *filename)
{
	int	fd;

	if (settings_texture_fd_check_dup(game, txt_type) != 0)
		return (EXIT_FAILURE);
	settings_rm_space_end(filename);
	if (ft_formatchr(filename, MAP_TEXT_FORMAT) == NULL)
		return (ft_panic(-1, __func__, ERR_MAP_TXT_FORMAT));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_panic(-1, __func__, ERR_FILEOPEN));
	settings_texture_fd_save_fd(game, txt_type, fd);
	settings_texture_fd_save_filename(game, txt_type, filename);
	return (0);
}
