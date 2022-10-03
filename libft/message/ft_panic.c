/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:33:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/10/03 10:04:10 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message.h"

int	ft_panic(int errcode, const char *filename, char *msg)
{
	int		res;
	char	*err_msg;

	res = 0;
	err_msg = NULL;
	if (errcode >= 0)
		err_msg = strerror(errcode);
	else if (msg)
		err_msg = msg;
	else
		err_msg = NULL;
	res += ft_putendl_fd_const("Error:", 2);
	res += ft_putstr_fd_const("cub3D", 2);
	res += ft_putstr_fd_const(": ", 2);
	if (filename)
	{
		res += ft_putstr_fd_const(filename, 2);
		res += ft_putstr_fd_const(": ", 2);
	}
	res += ft_putendl_fd_const(err_msg, 2);
	return (res);
}
