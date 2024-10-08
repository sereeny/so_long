/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:34:59 by ssandova          #+#    #+#             */
/*   Updated: 2024/10/07 18:02:58 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	error_print(int type)
{
	ft_printf("Error\n");
	if (type == 0)
		ft_printf("Use: ./so_long map.ber\n");
	else if (type == 1)
		ft_printf("Error opening map file. Must have extension .ber.\n");
	else if (type == 2)
		ft_printf("Error opening map file.\n");
	else if (type == 3)
		ft_printf("Map size is incorrect, walls are not around the map or \
	there are invalid characters.\n");
	else if (type == 4)
		ft_printf("There has to be one exit, (at least) one collectible \
and a starting position for the map to be valid.\n");
	else if (type == 5)
		ft_printf("The map given does not have a valid path.\n");
	else if (type == 6)
		ft_printf("Textures cannot be loaded.");
	else
		return ;
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < height && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	error_sl(t_map *game, int type)
{
	if (!game)
		return ;
	if (game)
	{
		if (game->map_cont)
		{
			free_map(game->map_cont, game->height);
			game->map_cont = NULL;
		}
		if (game->map_copy)
		{
			free_map(game->map_copy, game->height);
			game->map_copy = NULL;
		}
		free(game);
	}
	if (type >= 0)
		error_print(type);
}

void	free_mlx(t_mlxinfo *mlx)
{
	if (!mlx)
		return ;
	error_sl(mlx->map_info, -1);
	mlx_delete_image(mlx->mlx, mlx->collectible);
	mlx_delete_image(mlx->mlx, mlx->empty);
	mlx_delete_image(mlx->mlx, mlx->exit);
	mlx_delete_image(mlx->mlx, mlx->player);
	mlx_delete_image(mlx->mlx, mlx->wall);
}
