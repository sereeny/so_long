/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:48:20 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/13 19:56:34 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Crea un nuevo nodo utilizando malloc(3). La variable miembro ’content’ se
inicializa con el contenido del parámetro ’content’. La variable ’next’, 
con NULL.*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
