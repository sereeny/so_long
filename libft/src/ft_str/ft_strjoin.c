/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:07:36 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 13:14:53 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*strjoin() crea una cadena formada por str1 en combinación con str2. La cadena
devuelta se asigna fuera de la memoria temporal y, por lo tanto, sólo es válida
durante la duración de la cláusula. Si no hay suficiente espacio temporal 
disponible, strjoin no se ejecuta y se genera un error.*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr1 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr1 == NULL)
		return (NULL);
	ft_strlcpy(ptr1, s1, (ft_strlen(s1) + ft_strlen(s2) + 1));
	ft_strlcat(ptr1, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (ptr1);
}
