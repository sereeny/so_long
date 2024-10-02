/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:50:10 by ssandova          #+#    #+#             */
/*   Updated: 2024/10/02 17:57:52 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Checks that there is only one exit, at least one collectible and a starting
// position for the player, saving it in map->player_x and map->player_y.
static int	check_tokens(t_map *map)
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

// Saves each line of the map file in an the array in map.
static int	file_to_array(char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	temp = ft_calloc(1, 1);
	if (!line)
		return (close(fd), 1);
	while (line)
	{
		temp = ft_strjoin(temp, line);
		if (!temp)
			return (1);
		free(line);
		line = get_next_line(fd);
	}
	map->map_cont = ft_split(temp, '\n');
	map->map_copy = ft_split(temp, '\n');
	if (!map->map_cont || !map->map_copy)
		return (close(fd), free(temp), 1);
	return (close(fd), free(temp), 0);
}

// Returns 0 if the character given is a 0 (floor), 1 (wall), C (collectible),
// E (exit) or P (player).
static int	check_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (0);
	return (1);
}

//Checks map is rectangular, has walls on the borders and only has
//allowed characters.
static int	rectangle(t_map *map)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	while (map->map_cont[0][len] && map->map_cont[0][len] == '1')
		len++;
	i = 0;
	while (map->map_cont[++i])
	{
		j = 0;
		while (map->map_cont[i][j] && !check_char(map->map_cont[i][j]))
			j++;
		if (map->map_cont[i][0] != '1' || map->map_cont[i][j - 1] != '1' ||
		j != len)
			return (1);
	}
	j = 0;
	while (j < len)
	{
		if (map->map_cont[i - 1][j] != '1' || i < 3 || len < 3)
			return (1);
		j++;
	}
	return (map->height = i, map->width = len, 0);
}

int	parse_map(char *file, t_map *map)
{
	int i;
	int j;

	i = -1;
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		return (error_sl(map, 1), 1);
	if (file_to_array(file, map))
		return (error_sl(map, 2), 1);
	if (rectangle(map))
		return (error_sl(map, 3), 1);
	if (check_tokens(map))
		return (error_sl(map, 4), 1);
	flood_fill(map, map->player_x, map->player_y);
	while (++i < map->height)
	{
		j = -1;
		while (map->map_copy[i][++j])
		{
			if (map->map_copy[i][j] != 'F' && map->map_copy[i][j] != '0'
				&& map->map_copy[i][j] != '1' && map->map_copy[i][j] != '\0'
				&& map->map_copy[i][j] != '\n')
				return (error_sl(map, 5), 1);
		}
	}
	return (free_map(map->map_copy, map), 0);
}
