/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:09:15 by amarchan          #+#    #+#             */
/*   Updated: 2022/10/05 14:28:12 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	errors_handler(int err, const char *function_name)
{
	if (err == MALLOC_ERROR)
		printf("Error \nMemory allocation failed. Check function : %s \n",
			function_name);
	else if (err == NO_ADDRESS)
		printf("Error \nAddress not found. Check function : %s \n",
			function_name);
	return (err);
}
