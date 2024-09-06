/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:50:26 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/23 16:54:39 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Itera la lista ’lst’ y aplica la función ’f’ al contenido de cada nodo. Crea
una lista resultante de la aplicación correcta y sucesiva de la función ’f’
sobre cada nodo. La función ’del’ se utiliza para eliminar el contenido de un 
nodo, si hace falta.*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newlist;

	newlist = NULL;
	while (lst)
	{
		newnode = ft_lstnew(0);
		if (newnode == NULL)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		newnode->content = f(lst->content);
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
