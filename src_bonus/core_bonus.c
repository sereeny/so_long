/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:20:04 by ssandova          #+#    #+#             */
/*   Updated: 2024/11/09 11:38:29 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	close_mlx(t_mlxinfo *mlx, int type)
{
	mlx_close_window(mlx->mlx);
	free_mlx(mlx);
	if (type == 1)
		ft_printf("Game ended.\n");
	else if (type == 2)
		ft_printf("Error loading textures or images.\n");
	else if (type == 3)
		ft_printf("Game over!\n");
}

static void	print_player(t_mlxinfo *mlx, char m)
{
	int x;
	int y;

	x = mlx->map_info->player_x;
	y = mlx->map_info->player_y;
	if (mlx->player)
	{
		mlx_delete_image(mlx->mlx, mlx->player);
		if (m == 'w')
			mlx->player = mlx_tex_to_img(mlx->mlx, mlx->player, "textures/player_b.png");
		else if (m == 's')
			mlx->player = mlx_tex_to_img(mlx->mlx, mlx->player, "textures/player_f.png");
		else if (m == 'a')
			mlx->player = mlx_tex_to_img(mlx->mlx, mlx->player, "textures/player_l.png");
		else if (m == 'd')
			mlx->player = mlx_tex_to_img(mlx->mlx, mlx->player, "textures/player_r.png");
	}
	if (!mlx->player)
		close_mlx(mlx, 2);
	mlx_image_to_window(mlx->mlx, mlx->player, x * 64, y * 64);
}

static void	rem_and_new(t_mlxinfo *mlx, char m, int x, int y)
{
	char *output;

	if (mlx->map_info->map_cont[y][x] == 'C')
	{
		mlx->map_info->collectibles--;
		mlx->map_info->map_cont[y][x] = '0';
		if (!mlx_image_to_window(mlx->mlx, mlx->empty, x * 64, y * 64))
			close_mlx(mlx, 2);
		if (mlx->player && mlx->player->count > 0)
		{
			if (m == 'w')
				mlx->player->instances[0].y -= 64;
			else if (m == 's')
				mlx->player->instances[0].y += 64;
			else if (m == 'a')
				mlx->player->instances[0].x -= 64;
			else if (m == 'd')
				mlx->player->instances[0].x += 64;
		}
	}
	mlx->map_info->player_x = x;
	mlx->map_info->player_y = y;
	mlx->moves += 1;

	output = 
	mlx->text = mlx_put_string(mlx->mlx, )
	ft_printf("Moves: %i\n", mlx->moves);
}


static void	move_player(t_mlxinfo *mlx, char **map, int x, int y, char m)
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
	if (new_y >= 0 && new_y < mlx->map_info->height && new_x >= 0
	&& new_x < mlx->map_info->width && map[new_y] && map[new_y][new_x])
	{
		if (map[new_y][new_x] != '1')
		{
			rem_and_new(mlx, m, new_x, new_y);
			print_player(mlx, m);
		}
	}
}

void	my_keyhook_b(mlx_key_data_t key, void *mlx)
{
	t_mlxinfo	*dummy;
	int			x;
	int			y;

	dummy = (t_mlxinfo *)mlx;
	x = dummy->map_info->player_x;
	y = dummy->map_info->player_y;
	if ((dummy-> map_info->map_cont[y][x] == 'E' && dummy->map_info->
		collectibles == 0))
		close_mlx(mlx, 1);
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		close_mlx(mlx, 0);
	if (dummy->map_info->map_cont[y][x] == 'X')
		close_mlx(mlx, 3);
	else if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
		move_player(dummy, dummy->map_info->map_cont, x, y, 'w');
	else if (key.key == MLX_KEY_S && key.action == MLX_PRESS)
		move_player(dummy, dummy->map_info->map_cont, x, y, 's');
	else if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
		move_player(dummy, dummy->map_info->map_cont, x, y, 'a');
	else if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
		move_player(dummy, dummy->map_info->map_cont, x, y, 'd');
}
