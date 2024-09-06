/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:48:45 by ssandova          #+#    #+#             */
/*   Updated: 2024/08/12 13:22:23 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printchar(int character)
{
	write (1, &character, 1);
	return (1);
}
