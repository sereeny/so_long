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
	char	*line;
	char 	*tmp;
	int		fd;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return(error_sl(map, 1), 1);
	line = get_next_line(fd);
	if (!line)
		return (error_sl(map, 1), 1);
	tmp = (char *)malloc(sizeof(char) * 1);
	while (line)
	{
		tmp = ft_strjoin(tmp, line);
		if (!tmp)
			return (error_sl(map, 1), 1);
		line = get_next_line(fd);
	}
	(*map)->map = ft_split(tmp, '\n');
	return (close(fd), 0);
}

static int		rectangle(char **map)
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

int	parse_map(char *file, t_map **map)
{
	if (!file_to_array(file, map) || !rectangle((*map)->map))
		return (error_sl(map, 2), 1);
	return (0);
}
