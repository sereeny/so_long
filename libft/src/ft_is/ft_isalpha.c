/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:22:59 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/20 22:48:08 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The isalpha() function tests for any character for which isupper(3) or 
islower(3) is true.  The value of the argument must be representable as an 
unsigned char or the value of EOF.*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
