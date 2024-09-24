/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:02:47 by ssandova          #+#    #+#             */
/*   Updated: 2024/09/24 19:36:52 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	int i = 0;
	t_map	*map;

	if ((argc == 1)|| (!argv[1][0]))
		return (error_sl(NULL, 0) ,1);
	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (1);
	if (parse_map(argv[1], map))
	{
		while (map->map[i] != NULL) 
		{
        	printf("%s\n", map->map[i]);
        	i++;
		}
		return (1);
	}
//	mlx_t	*mlx;
//	mlx = mlx_init(256, 256, "42", true);
//	if (!mlx)
//		return (1);
//	mlx_loop(mlx);
}
