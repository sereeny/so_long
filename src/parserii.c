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

static int	manage_visited(t_map *map, int type)
{
	int		i;

	if (type == 1)
	{
		map->visited = (bool **)ft_calloc(map->height, sizeof(map->visited));
		if (!map->visited)
			return (1);
	}
	if (type == 2)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->visited[i]);
			i++;
		}
		free(map->visited);
	}
	return (0);
}

static int	find_path(t_map *map, int x, int y)
{
	bool	up;
	bool	left;
	bool	right;
	bool	down;

	if (map->map_cont[x][y] != '1' && !map->visited[x][y] && x >= 0 && \
		x <= map->height && y >= 0 && y <= map->width)
	{
		map->visited[x][y] = true;
		if (map->map_cont[x][y] == 'E')
			return (0);
		up = find_path(map, x - 1, y);
		if (up)
			return (0);
		left = find_path(map, x - 1, y);
		if (left)
			return (0);
		down = find_path(map, x + 1, y);
		if (down)
			return (0);
		right = find_path(map, x, y + 1);
		if (right)
			return (0);
	}
	return (1);
}

int	valid_path(t_map *map)
{
	bool	flag;
	int		i;
	int		j;

	if (manage_visited(map, 1))
		return (1);
	i = -1;
	j = -1;
	while (++i < map->height)
	{
		while (++j < map->width)
		{
			if (map->map_cont[i][j] == 'P' && !map->visited[i][j])
			{
				if (find_path(map, i, j) == 0)
				{
					flag = true;
					break ;
				}
			}
		}
	}
	if (!flag)
		return (manage_visited(map, 2), 1);
	return (0);
}
