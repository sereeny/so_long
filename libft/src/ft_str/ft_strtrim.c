/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:32:43 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 15:48:57 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Elimina todos los caracteres de la string ’set’ desde el principio y desde el
final de ’s1’, hasta encontrar un caracter no perteneciente a ’set’. La string
resultante se devuelve con una reserva de malloc(3)*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptrim;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (j >= 0 && ft_strchr(set, s1[j]) != NULL)
		j--;
	len = j - i + 1;
	if (i > j)
		len = 0;
	ptrim = malloc(len + 1);
	if (ptrim == NULL)
		return (NULL);
	if (len > 0)
		ft_memcpy(ptrim, &s1[i], len);
	ptrim[len] = '\0';
	return (ptrim);
}
/*
int	main()
{
	printf("%s", ft_strtrim("", ""));
	return (0);
}*/