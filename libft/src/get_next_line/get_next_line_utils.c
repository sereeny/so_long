/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:35:22 by ssandova          #+#    #+#             */
/*   Updated: 2024/08/12 13:22:56 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*-----------------------------------------------------------------------------
The calloc() function contiguously allocates enough space for count objects 
that are size bytes of memory each and returns a pointer to the allocated memory.
The allocated memory is filled with bytes of value zero.
------------------------------------------------------------------------------*/

void	*ft_calloc_gnl(size_t count, size_t size)
{
	unsigned char	*pointer;
	size_t			siz;
	size_t			i;

	siz = count * size;
	pointer = malloc(siz);
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (i < siz)
		pointer[i++] = 0;
	return (pointer);
}

/*---------------------------------------------------------------------------
The strchr() function locates the first occurrence of c (converted to a char) 
in the string pointed to by s.  The terminating null character is considered 
to be part of the string; therefore if c is `\0', the functions locate the
terminating `\0'.
----------------------------------------------------------------------------*/
char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

/*---------------------------------------------------------------------------
Returns the substring of the given string at the given start position with 
the given length.
----------------------------------------------------------------------------*/
char	*ft_substr_gnl(char const *s, int start, int len)
{
	char	*pointer;
	int		i;

	if (start >= ft_strlen_gnl(s))
		return (ft_calloc_gnl(1, 1));
	if (len + start > ft_strlen_gnl(s))
		len = ft_strlen_gnl(s) - start;
	pointer = (char *)ft_calloc_gnl(len + 1, sizeof(char));
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < len)
		pointer[i++] = s[start++];
	return (pointer);
}

/*---------------------------------------------------------------------------
The strlen() function computes the length of the string s.
----------------------------------------------------------------------------*/
int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*---------------------------------------------------------------------------
Strjoin() creates a string made up of str1 in combination with str2. String
returned is allocated outside of temporary memory and is therefore only valid
during the duration of the clause. If there is not enough temporary space
available, strjoin is not executed and an error is generated.
----------------------------------------------------------------------------*/
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;

	if (s1 == NULL)
		return (ft_strdup_gnl(s2));
	if (s2 == NULL)
		return (ft_strdup_gnl(s1));
	joined = (char *)ft_calloc_gnl(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) \
			+ 1, sizeof(char));
	if (joined == NULL)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		joined[i] = s1[i];
	while (s2[j])
		joined[i++] = s2[j++];
	free(s1);
	return (joined);
}
