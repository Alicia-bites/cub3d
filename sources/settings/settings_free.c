/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:00:55 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 15:04:56 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	settings_free(t_settings *settings)
{
	settings_free_close_fd(&settings->fd_no);
	settings_free_close_fd(&settings->fd_so);
	settings_free_close_fd(&settings->fd_we);
	settings_free_close_fd(&settings->fd_ea);
}
