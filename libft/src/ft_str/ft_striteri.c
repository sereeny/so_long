/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:39:49 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 18:04:10 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A cada carácter de la string ’s’, aplica la función ’f’ dando como parámetros 
el índice de cada carácter dentro de ’s’ y la dirección del propio carácter, 
que podrá modificarse si es necesario.*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f((unsigned int)i, &s[i]);
		i++;
	}
	s[i] = '\0';
}
