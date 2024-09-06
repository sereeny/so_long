/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:22:51 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 18:32:40 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Envía la string ’s’ al file descriptor dado, seguido de un salto de línea.*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		write(fd, &s[i], 1);
	write(fd, "\n", 1);
}
