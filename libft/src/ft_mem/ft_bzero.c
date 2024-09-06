/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:48:04 by ssandova          #+#    #+#             */
/*   Updated: 2023/10/07 13:05:22 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The bzero() function writes n zeroed bytes to the string s.  If n is zero, 
bzero() does nothing.*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
