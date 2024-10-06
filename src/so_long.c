/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:02:47 by ssandova          #+#    #+#             */
/*   Updated: 2024/10/05 20:35:07 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <errno.h>

void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

void	load_map(t_mlxinfo *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i <= mlx->map_info->height)
	{
		j = 0;
		while (j <= mlx->map_info->width)
		{
			if (mlx->map_info->map_cont[i][j] == '1')
				mlx_image_to_window(mlx->mlx, mlx->wall, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

t_mlxinfo	*mlx_initialize(t_map *map)
{
	t_mlxinfo		*mlx;
	mlx_texture_t	*img;

	mlx = (t_mlxinfo *)ft_calloc(sizeof(t_mlxinfo), 1);
	if (!mlx)
		return (NULL);
	mlx->map_info = map;
	mlx->mlx = mlx_init(mlx->map_info->width * 64, mlx->map_info->height * 64, "so long", \
		false);
	img = mlx_load_png("textures/wall.png");
	mlx->wall = mlx_texture_to_image(mlx->mlx, img);
	// img = mlx_load_png("textures/player.png");
	// mlx->player = mlx_texture_to_image(mlx->mlx, img);
	// img = mlx_load_png("textures/exit.png");
	// mlx->exit = mlx_texture_to_image(mlx->mlx, img);
	// img = mlx_load_png("textures/empty.png");
	// mlx->empty = mlx_texture_to_image(mlx->mlx, img);
	// img = mlx_load_png("textures/collectible.png");
	// mlx->collectible = mlx_texture_to_image(mlx->mlx, img);
	// if (!mlx->collectible || !mlx->empty || !mlx->exit || !mlx->map_info || 
	// 	!mlx->player || mlx->wall)
	// 	return (error_sl(map, 6), NULL);
	return (mlx);

}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_mlxinfo	*mlx;

	if ((argc != 2) || (!argv[1][0]))
		return (error_sl(NULL, 0), 1);
	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (1);
	if (parse_map(argv[1], map))
		return (1);
	mlx = mlx_initialize(map);
	if (!mlx )
		return (1);
	load_map(mlx);
	mlx_loop(mlx->mlx);
	mlx_terminate(mlx->mlx);
	return (0);
}
