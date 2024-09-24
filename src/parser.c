/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:50:10 by ssandova          #+#    #+#             */
/*   Updated: 2024/09/24 19:33:45 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	map->map = ft_split(temp, '\n'); 
	if (!map->map)
		return (close(fd), free(temp), 1);
	return (close(fd), free(temp), 0);
}

/*• The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position*/
// checks that the characters from the map are 0, 1, C, E or P.
static int    check_char(char    c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return 0;
	return 1;
}    

//checks map is rectangular and has walls on the borders
static int    rectangle(t_map *map)
{
	int len;
	int i;
	int j;

	len = 0;
	while(map->map[0][len] && map->map[0][len] == '1') 
		len++;
	i = 1;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] && !check_char(map->map[i][j]))
			j++;
		if (map->map[i][0] != '1' || map->map[i][j - 1] != '1' || j != len)
			return(1);
		i++;
	}
	j = 0;
	while (j < len)
	{
		if (map->map[i - 1][j] != '1' || i < 3 || len < 3)
			return(1);
		j++;
	}
	return (0);
}

int	parse_map(char *file, t_map *map)
{
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		return (error_sl(map, 1), 1);
	if (!file_to_array(file, map) || !rectangle((map)))
		return (error_sl(map, 2), 1);
	return (0);
}
