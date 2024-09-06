/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:04:19 by ssandova          #+#    #+#             */
/*   Updated: 2024/08/12 13:22:37 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_printchar('0');
	else
	{
		if (n / 10 > 0)
			ft_unsigned(n / 10);
		ft_printchar((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			size++;
		}
	}
	return (size);
}

int	ft_printnbr(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size += ft_printchar('-');
		n *= -1;
	}
	size += ft_unsigned((unsigned int)n);
	return (size);
}
