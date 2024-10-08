/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:50:24 by ssandova          #+#    #+#             */
/*   Updated: 2024/08/28 15:28:16 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: split string, with specified character as delimiter, into an array
**	of strings
**
** DESCRIPTION:
** 	Allocates (with malloc(3)) and returns an array of strings obtained by
**	splitting ’s’ using the character ’c’ as a delimiter. The array must be
**	ended by a NULL pointer.
*/

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	bool;
	int	count;
	int	i;

	i = 0;
	bool = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && bool == 0)
		{
			count++;
			bool += 1;
		}
		else if (s[i] == c && bool == 1)
			bool -= 1;
		i++;
	}
	return (count);
}

static char	*ft_strings(char const *s, int st, int fi)
{
	char		*string;
	int			i;

	i = 0;
	string = (char *)malloc((fi - st + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	while (st < fi)
	{
		string[i] = s[st];
		i++;
		st++;
	}
	string[i] = '\0';
	return (string);
}

static void	ft_free(int j, char **array)
{
	while (--j >= 0)
		free(array[j]);
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		st;
	int		i;
	int		j;

	array = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	i = -1;
	st = -1;
	j = 0;
	if (s == NULL || array == NULL)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && st < 0)
			st = i;
		else if ((i == ft_strlen(s) || s[i] == c) && st >= 0)
		{
			array[j++] = ft_strings(s, st, i);
			if (array[j - 1] == NULL)
				return (ft_free(j, array), NULL);
			st = -1;
		}
	}
	array[j] = NULL;
	return (array);
}
