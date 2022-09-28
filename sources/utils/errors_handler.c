/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:09:15 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/28 14:27:17 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	errors_handler(int err, const char *function_name)
{
	if (err == MALLOC_ERROR)
		printf("Memory allocation failed. Check %s\n", function_name);
	return (err);
}