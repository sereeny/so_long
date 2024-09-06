/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:00:06 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/11 20:02:42 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Utilizando malloc(3), genera una string que represente el valor entero 
recibido como argumento. Los números negativos tienen que gestionarse.*/

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*buffer;
	int			len;
	long int	nbr;

	nbr = (long int)n;
	len = count_digits(nbr);
	buffer = (char *)malloc(len + 1);
	if (buffer == NULL)
		return (NULL);
	buffer[len--] = '\0';
	if (nbr == 0)
		buffer[0] = '0';
	if (nbr < 0)
	{
		buffer[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		buffer[len--] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return ((char *)buffer);
}
