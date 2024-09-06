/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:01:53 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 13:10:26 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The memcmp() function compares byte string s1 against byte string s2. 
Both strings are assumed to be n bytes long.*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*st1 == *st2)
		{
			n--;
			st1++;
			st2++;
		}
		else
		{
			return ((int)*st1 - (int)*st2);
		}
	}
	return ('\0');
}
