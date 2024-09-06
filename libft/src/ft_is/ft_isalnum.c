/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:24:50 by ssandova          #+#    #+#             */
/*   Updated: 2024/08/07 16:31:22 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The isalnum() function tests for any character for which isalpha(3) or 
isdigit(3) is true.  The value of the argument must be representable as an 
unsigned char or the value of EOF.*/

#include "../../inc/libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
