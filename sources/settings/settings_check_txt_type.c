/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_check_txt_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:23:59 by abarrier          #+#    #+#             */
/*   Updated: 2022/09/21 16:28:56 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	settings_check_txt_type(t_settings *settings)
{
	if (settings->fd_no < 0 || settings->fd_so < 0
		|| settings->fd_we < 0 || settings->fd_ea < 0)
		return (ft_panic(-1, __func__, ERR_MAP_TXT_TYPE));
	else if (settings->f_r < 0 || settings->c_r < 0)
		return (ft_panic(-1, __func__, ERR_MAP_TXT_TYPE));
	else
		return (0);
}
