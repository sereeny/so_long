/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:06:12 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 18:09:55 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Envía el carácter ’c’ al file descriptor especificado.*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
