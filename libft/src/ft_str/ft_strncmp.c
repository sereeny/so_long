/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:23:46 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 13:19:33 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strncmp() function compares not more than n characters.  Because strncmp()
is designed for comparing strings rather than binary data, characters that 
appear after a `\0' character are not compared.*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char) s1[i] == (unsigned char) s2[i])
			i++;
		else if ((unsigned char) s1[i] < (unsigned char) s2[i])
			return (-1);
		else if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return (1);
	}
	return (0);
}
