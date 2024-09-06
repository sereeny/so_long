/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:21:57 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 13:17:17 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*strlcpy() and strlcat() take the full size of the destination buffer and 
guarantee NUL-termination if there is room. Note that room for the NUL should 
be included in dstsize.
strlcpy() copies up to dstsize - 1 characters from the string src to dst, 
NUL-terminating the result if dstsize is not 0.*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (src != NULL)
	{
		if (dst != NULL && dstsize != 0)
		{
			i = 0;
			while ((i < len) && i < (dstsize - 1))
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
	}
	return (len);
}
