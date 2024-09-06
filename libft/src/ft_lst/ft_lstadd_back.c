/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:23:28 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/13 21:11:01 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Añade el nodo ’new’ al final de la lista ’lst’.*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	aux = ft_lstlast(*lst);
	if (aux != NULL && new != NULL)
		aux->next = new;
	else
		*lst = new;
}
