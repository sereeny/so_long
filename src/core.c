/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:20:04 by ssandova          #+#    #+#             */
/*   Updated: 2024/10/08 00:02:16 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	rem_and_new(t_mlxinfo *mlx, int x, int y)
{
	if (mlx->map_info->map_cont[y][x] == 'C')
	{
		mlx->map_info->collectibles--;
		mlx_image_to_window(mlx->mlx, mlx->wall, x * 64, y * 64);
	}
	mlx->map_info->player_x = x;
	mlx->map_info->player_y = y;
}


void	move_player(t_mlxinfo *mlx, char **map, int x, int y, char m)
{
	int	new_x;
	int new_y;

	new_x = x;
	new_y = y;
	if (m == 'w')
		new_y--;
	else if (m == 's')
		new_y++;
	else if (m == 'a')
		new_x--;
	else if (m == 'd')
		new_x++;
	if (new_y < mlx->map_info->height && new_y >= 0 && new_x >= 0 && \
		new_x < mlx->map_info->width && map[new_y][new_x])
	{
		if (map[new_y][new_x] != '1')
		{

//			rem_and_new(mlx, new_x, new_y);
		}
	}
}

void	my_keyhook(mlx_key_data_t key, void *mlx)
{
	t_mlxinfo	*dummy;
	int			x;
	int			y;

	dummy = (t_mlxinfo *)mlx;
	x = dummy->map_info->player_x;
	y = dummy->map_info->player_y;
	dummy->map_info->collectibles = 0;
	if ((key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS) || (dummy-> \
		map_info->map_cont[y][x] == 'E' && dummy->map_info->collectibles == 0))
	{
		free_game(dummy->map_info->map_cont, dummy->map_info);
		mlx_close_window(dummy->mlx);
	}
	else if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
		move_player(dummy, dummy->map_info->map_cont, x, y, 'w');
	else if (key.key == MLX_KEY_S && key.action == MLX_PRESS)
		move_player(dummy, dummy->map_info->map_cont, x, y, 's');
	else if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
		move_player(dummy, dummy->map_info->map_cont, x, y, 'a');
	else if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
		move_player(dummy, dummy->map_info->map_cont, x, y, 'd');
}
