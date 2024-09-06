/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:49:59 by ssandova          #+#    #+#             */
/*   Updated: 2024/08/12 13:22:42 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_formats(va_list element, char const format)
{
	int	size;

	size = 0;
	if (format == 'c')
		size += ft_printchar(va_arg(element, int));
	else if (format == 's')
		size += ft_printstr(va_arg(element, char *));
	else if (format == 'd' || format == 'i')
		size += ft_printnbr(va_arg(element, int));
	else if (format == 'u')
		size += ft_unsigned(va_arg(element, unsigned int));
	else if (format == 'x' || format == 'X')
		size += ft_hexadecimal(va_arg(element, unsigned int), format);
	else if (format == 'p')
		size += ft_pointer((unsigned long)va_arg(element, void *));
	if (format == '%')
		size += ft_printchar(format);
	return (size);
}

int	ft_printf(char const *str, ...)
{
	int			i;
	va_list		element;
	int			size;

	i = 0;
	size = 0;
	if (write (1, "", 0) == -1)
		return (-1);
	va_start(element, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_formats(element, str[i + 1]);
			i++;
		}
		else
			size += ft_printchar(str[i]);
		i++;
	}
	va_end(element);
	return (size);
}
/*
int	main(void)
{
	printf("%s\n", "hola que tal");
	ft_printf("%s", "hola que tal");
}
*/