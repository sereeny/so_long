/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:37:35 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 13:09:59 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The memchr() function locates the first occurrence of c (converted to an 
unsigned char) in string s.*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		if (*p == (unsigned char)c)
			return (p);
		p++;
		n--;
	}
	return (NULL);
}
