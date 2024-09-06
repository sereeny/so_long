/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:00:14 by ssandova          #+#    #+#             */
/*   Updated: 2024/07/19 11:48:35 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Itera la lista ’lst’ y aplica la función ’f’ en el contenido de cada nodo.*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int		size;

	size = ft_lstsize(lst);
	while (lst != NULL || size > 0)
	{
		f(lst->content);
		lst = lst->next;
		size--;
	}
}
