/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:47:25 by ssandova          #+#    #+#             */
/*   Updated: 2024/09/25 11:43:34 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	update_position(t_map *map, int x, int y)
{
	map->player++;
	map->player_x = x;
	map->player_y = y;
}

int	valid_path(t_map *map)
{
	
}
