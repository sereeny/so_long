/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:02:47 by ssandova          #+#    #+#             */
/*   Updated: 2024/09/18 20:20:33 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

int	main(int argc, char **argv)
{
	t_map	*map;

	if ((argc == 1)|| (!argv[1][0]))
		return (1);
	map = (t_map *)calloc(sizeof(t_map), 1);
	if (!map)
		return (1);
	if (!parse_map(argv[1], &map))
		return (1);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		return (1);

//	char **map = parse_map(argv[1]);
/*	mlx_t	*mlx;
	mlx = mlx_init(256, 256, "42", true);
	if (!mlx)
		return (1);
	// mlx_loop(mlx);*/
}
