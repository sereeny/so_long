/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:41:00 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 15:01:42 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strlen() function computes the length of the string s.  The strnlen() 
function attempts to compute the length of s, but never scans beyond the first 
maxlen bytes of s.*/

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
