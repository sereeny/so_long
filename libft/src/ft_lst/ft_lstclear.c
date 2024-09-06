/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:20:15 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/20 22:47:58 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Elimina y libera el nodo ’lst’ dado y todos los consecutivos de ese nodo, 
utilizando la función ’del’ y free(3). Al final, el puntero a la lista debe 
ser NULL.*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	while (*lst != NULL)
	{
		aux = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(aux, del);
	}
}
