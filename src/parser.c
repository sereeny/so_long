/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:50:10 by ssandova          #+#    #+#             */
/*   Updated: 2024/09/25 00:43:48 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
			if (map->map_content[i][j] == 'E')
				map->exit++;
			else if (map->map_content[i][j] == 'P');
				//update position;
			else if (map->map_content[i][j] == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
	if (map->exit != 1 || map->collectibles < 0 || map->player != 1)
		return (1);
	return (0);
}

// put each line of the file in a matrix with gnl.
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
	map->map_content = ft_split(temp, '\n'); 
	if (!map->map_content)
		return (close(fd), free(temp), 1);
	return (close(fd), free(temp), 0);
}

/*• The map can be composed of only these 5 characters:
0 for an empty space, 1 for a wall, C for a collectible, E for a map exit,
P for the player’s starting position.*/
static int    check_char(char    c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return 0;
	return 1;
}    

//checks map is rectangular, has walls on the borders and only has allowed characters.
static int    rectangle(t_map *map)
{
	int len;
	int i;
	int j;

	len = 0;
	while(map->map_content[0][len] && map->map_content[0][len] == '1') 
		len++;
	i = 1;
	while (map->map_content[i])
	{
		j = 0;
		while (map->map_content[i][j] && !check_char(map->map_content[i][j]))
			j++;
		if (map->map_content[i][0] != '1' || map->map_content[i][j - 1] != '1' || j != len)
			return(1);
		i++;
	}
	j = 0;
	while (j < len)
	{
		if (map->map_content[i - 1][j] != '1' || i < 3 || len < 3)
			return(1);
		j++;
	}
	return (map->height = i, map->width = len, 0);
}

int	parse_map(char *file, t_map *map)
{
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		return (error_sl(map, 1), 1);
	if (file_to_array(file, map))
		return (error_sl(map, 2), 1);
	if (rectangle(map))
		return (error_sl(map, 3), 1);
	if (check_tokens(map))
		return (error_sl(map, 4), 1);
	return (0);
}
