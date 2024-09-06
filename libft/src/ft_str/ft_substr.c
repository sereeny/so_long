/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:07:41 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/13 13:51:20 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Reserva (con malloc(3)) y devuelve una substring de la string ’s’. La 
substring empieza desde el índice ’start’ y tiene una longitud máxima ’len’.*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	ptr = (char *)malloc((sizeof(char) * len + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
