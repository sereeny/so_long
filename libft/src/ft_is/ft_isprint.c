/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:52:51 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 13:09:29 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The isprint() function tests for any printing character, including space 
(` ').  The value of the argument must be representable as an unsigned char or 
the value of EOF.*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
