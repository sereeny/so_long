/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserii_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:47:25 by ssandova          #+#    #+#             */
/*   Updated: 2024/10/15 23:27:42 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Checks that there is only one exit, at least one collectible and a starting
// position for the player, saving it in map->player_x and map->player_y.
int	check_tokens(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_cont[i][j] == 'E')
				map->exit++;
			else if (map->map_cont[i][j] == 'P')
				update_position(map, j, i);
			else if (map->map_cont[i][j] == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
	if (map->exit != 1 || map->collectibles < 1 || map->player != 1)
		return (1);
	return (0);
}

void	update_position(t_map *map, int x, int y)
{
	map->player++;
	map->player_x = x;
	map->player_y = y;
}

void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (map->map_copy[y][x] == '1' || map->map_copy[y][x] == 'X' || \
		map->map_copy[y][x] == 'F')
		return ;
	map->map_copy[y][x] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}
