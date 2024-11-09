/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:50:10 by ssandova          #+#    #+#             */
/*   Updated: 2024/11/09 11:29:31 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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
	while (line)
	{
		aux = ft_strjoin(temp, line);
		free(temp);
		if (!aux)
			return (free(line), NULL);
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
// E (exit), P (player) or X (enemy patrol).
static int	check_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == 'X')
		return (0);
	return (1);
}

//Checks map is rectangular, has walls on the borders and only has
//allowed characters.
static int	rectangle(t_map *map)
{
	int		len;
	int		i;
	int		j;
	char	**map_ar;

	len = 0;
	map_ar = map->map_cont;
	while (map_ar[0][len] && map_ar[0][len] == '1')
		len++;
	i = 0;
	while (map_ar[++i])
	{
		j = 0;
		while (map_ar[i][j] && !check_char(map_ar[i][j]))
			j++;
		if (map_ar[i][0] != '1' || map_ar[i][j - 1] != '1' || j != len)
			return (0);
	}
	j = -1;
	while (++j < len)
	{
		if (map_ar[i - 1][j] != '1' || i < 3 || len < 3)
			return (0);
	}
	return (map->height = i, map->width = len, 1);
}

int	parse_map_bonus(char *file, t_map *map)
{
	int	i;
	int	j;

	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		return (error_sl(map, 1), 0);
	if (!file_to_array(file, map))
		return (error_sl(map, 2), 0);
	if (!rectangle(map))
		return (error_sl(map, 3), 0);
	if (!check_tokens(map))
		return (error_sl(map, 4), 0);
	flood_fill_bonus(map, map->player_x, map->player_y);
	i = -1;
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
