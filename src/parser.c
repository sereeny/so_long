/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:50:10 by ssandova          #+#    #+#             */
/*   Updated: 2024/09/20 20:01:52 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	file_to_array(char *file, t_map **map)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_sl(map, 1), 1);
	line = get_next_line(fd);
	temp = (char *)ft_calloc(1, 1);
	temp = " ";
	while (line)
	{
		temp = ft_strjoin(temp, line);
		line = get_next_line(fd);
	}
	(*map)->map = ft_split(temp, '\n'); 
	if (!(*map)->map)
		return (error_sl(map, 1), free(line), free(temp), 1);
	return (free(line), free(temp), 0);
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

static int    rectangle(char **map)
{
    int len;
    int i;
    int j;

    len = 0;
    while(map[0][len] && map[0][len] == '1') 
        len++;
    i = 1;
    while (map[i])
    {
        j = 0;
        while (map[i][j] && !check_char(map[i][j]))
            j++;
        if (map[i][0] != '1' || map[i][j - 1] != '1' || j != len)
            return(error_sl(map, 2), 1);
        i++;
    }
    j = 0;
    while (j < len)
    {
        if (map[i - 1][j] != '1')
            return(error_sl(map, 2), 1);
        j++;
    }
    return (0);
}

int	parse_map(char *file, t_map **map)
{
	if (!file_to_array(file, map) || !rectangle((*map)->map))
		return (error_sl(map, 2), 1);
	return (0);
}
