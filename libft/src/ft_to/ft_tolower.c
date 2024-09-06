/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:11:06 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 13:23:41 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The tolower() function converts an upper-case letter to the corresponding 
lower-case letter.  The argument must be representable as an unsigned char or 
the value of EOF.*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
