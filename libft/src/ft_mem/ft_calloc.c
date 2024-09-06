/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:27:50 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 13:06:07 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The calloc() function contiguously allocates enough space for count objects 
that are size bytes of memory each and returns a pointer to the allocated memory.
The allocated memory is filled with bytes of value zero.*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pun;

	pun = malloc(size * count);
	if (pun == 0)
		return (0);
	ft_bzero(pun, count * size);
	return (pun);
}
