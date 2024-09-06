/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:45:19 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/20 22:48:02 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The isascii() function tests for an ASCII character, which is any character 
between 0 and octal 0177 inclusive.*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
