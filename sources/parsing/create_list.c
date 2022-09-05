/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:42:23 by amarchan          #+#    #+#             */
/*   Updated: 2022/09/05 11:42:34 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_list	*create_list(char *line)
{
	static int		i = 0;
	static t_list	*lst;
	t_list			*new;

	if (ft_strlen(line) < 2)
	{
		free(line);
		ft_panic(EMPTY_LINE, 0, &lst);
	}
	if (i == 0)
		lst = ft_lstnew(line, i);
	else
	{
		new = ft_lstnew(line, i);
		ft_lstadd_back(&lst, new);
	}	
	i++;
	return (lst);
}