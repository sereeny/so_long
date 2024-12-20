/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:50:10 by ssandova          #+#    #+#             */
/*   Updated: 2024/11/09 13:23:46 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Opens fd, reads each like and returns a string with all the lines joined.
static char	*read_map_file(int fd)
{
	char	*line;
	char	*temp;
	char	*aux;

	temp = ft_calloc(1, 1);
	if (!temp)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (free(temp), free(line), NULL);
	while (line)
	{
		aux = ft_strjoin(temp, line);
		free(temp);
		if (!aux)
			return (free(line), free(temp), NULL);
		temp = aux;
		free(line);
		line = get_next_line(fd);
	}
	return (temp);
}

// Saves each line of the map file in an the array in map.
static int	file_to_array(char *file, t_map *map)
{
	int		fd;
	char	*s;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	s = read_map_file(fd);
	close (fd);
	if (!s)
		return (0);
	map->map_cont = ft_split(s, '\n');
	map->map_copy = ft_split(s, '\n');
	free(s);
	if (!map->map_cont || !map->map_copy)
		return (0);
	return (1);
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
			return (0);
	}
	j = 0;
	while (j < len)
	{
		if (map->map_cont[i - 1][j] != '1' || i < 3 || len < 3)
			return (0);
		j++;
	}
	return (map->height = i, map->width = len, 1);
}

int	parse_map(char *file, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		return (error_sl(map, 1), 0);
	if (!file_to_array(file, map))
		return (error_sl(map, 2), 0);
	if (!rectangle(map))
		return (error_sl(map, 3), 0);
	if (!check_tokens(map))
		return (error_sl(map, 4), 0);
	flood_fill(map, map->player_x, map->player_y);
	while (++i < map->height)
	{
		j = -1;
		while (map->map_copy[i][++j])
		{
			if (map->map_copy[i][j] == 'C' || map->map_copy[i][j] == 'E' ||
				map->map_copy[i][j] == 'P')
				return (error_sl(map, 5), 0);
		}
	}
	return (free_map(map->map_copy, map->height), map->map_copy = NULL, 1);
}
