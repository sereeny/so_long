/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:34:59 by ssandova          #+#    #+#             */
/*   Updated: 2024/10/02 16:31:31 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	error_print(int type)
{
	ft_printf("Error\n");
	if (type == 0)
		ft_printf("Use: ./so_long [map.ber]\n");
	else if (type == 1)
		ft_printf("Error opening map file. Must have extension .ber.\n");
	else if (type == 2)
		ft_printf("Error opening map file.\n");
	else if (type == 3)
		ft_printf("Map size is incorrect, walls are not around the map or \
	there are invalid characters.\n");
	else if (type == 4)
		ft_printf("There has to be one exit, (at least) one collectible \
and a starting position for the map to be valid.\n");
	else if (type == 5)
		ft_printf("The map given does not have a valid path.\n");
}

void	error_sl(t_map *game, int type)
{
	if (game)
		free(game);
	error_print(type);
}

void	free_map(char **map, t_map *game)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return ;
	while (i < game->height)
	{
		free(map[i]);
		i++;
	}
	free(map);
	game->map_copy = NULL;
}
