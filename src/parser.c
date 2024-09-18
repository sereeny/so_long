/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:50:10 by ssandova          #+#    #+#             */
/*   Updated: 2024/09/18 20:25:41 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	file_to_array(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return(error_sl(map, 1), 1);
}

int		rectangle(char **map)
{
	int len;
	int i;
	int j;

	i = 1;
	while(map[0][len] != '\0' && map[0][len] == '1') 
		len++;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != len)
			return (1);
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (1);
		i++;
	}
	j = -1;
	while (map[i] && j <= len)
	{
		if (map[i][++j] != '1')
			return (1);
	}
	return (0);
}

int	parse_map(char *file, t_map *map)
{
	file_to_array(file, map);
}
