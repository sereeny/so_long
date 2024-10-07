/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:20:04 by ssandova          #+#    #+#             */
/*   Updated: 2024/10/07 20:19:40 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
			mlx->map_info->player_x = new_x;
			mlx->map_info->player_y = new_y;
			mlx_image_to_window(mlx->mlx, mlx->player, mlx->map_info->player_x * 64, \
		mlx->map_info->player_y * 64);
			ft_printf("X es %i\nY es %i\n", mlx->map_info->player_x, mlx->map_info->player_y);
		}
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *mlx)
{
	t_mlxinfo	*dummy;
	int			x;
	int			y;

	dummy = (t_mlxinfo *)mlx;s
	x = dumm
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS || dummy->map_info->map_cont[][])
	{
		free_game(dummy->map_info->map_cont, dummy->map_info);
		mlx_close_window(dummy->mlx);s
	}
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(dummy, dummy->map_info->map_cont, dummy->map_info-> \
			player_x, dummy->map_info->player_y, 'w');
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)s
		move_player(dummy, dummy->map_info->map_cont, dummy->map_info-> \
			player_x, dummy->map_info->player_y, 's');
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(dummy, dummy->map_info->map_cont, dummy->map_info-> \
			player_x, dummy->map_info->player_y, 'a');
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(dummy, dummy->map_info->map_cont, dummy->map_info-> \
			player_x, dummy->map_info->player_y, 'd');
}
