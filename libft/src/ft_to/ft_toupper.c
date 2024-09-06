/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:03:39 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 13:24:16 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*he toupper() function converts a lower-case letter to the corresponding 
upper-case letter. The argument must be representable as an unsigned char or 
the value of EOF.*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
