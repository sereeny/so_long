/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:47:25 by ssandova          #+#    #+#             */
/*   Updated: 2024/10/02 17:02:25 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	if (map->map_copy[y][x] == '1' || map->map_copy[y][x] == 'F')
		return ;
	map->map_copy[y][x] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}
