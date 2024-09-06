/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:33:36 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 19:36:17 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Envía el número ’n’ al file descriptor dado.*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = (long int) n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd((nbr % 10), fd);
	}
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', fd);
}
