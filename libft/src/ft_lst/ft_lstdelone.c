/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:10:19 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/17 19:17:37 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Toma como parámetro un nodo ’lst’ y libera la memoria del contenido 
utilizando la función ’del’ dada como parámetro, además de liberar el nodo. La
memoria de ’next’ no debe liberarse.*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		del(lst->content);
		free (lst);
	}
}
