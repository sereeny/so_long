/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:34:59 by ssandova          #+#    #+#             */
/*   Updated: 2024/09/18 19:53:10 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


int ft_strlen_sl(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	error_sl(t_game **game, int type)
{
	if (game)
		free(game);
	error_print(type);
}

static void	error_print(int type)
{
	ft_printf("Error\n");
	if (type == 0)
		ft_printf("Use: ./so_long [map.ber]\n");
	else if (type == 1)
		ft_printf("No map file.\n");
}
