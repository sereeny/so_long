/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:02:47 by ssandova          #+#    #+#             */
/*   Updated: 2024/11/09 13:14:44 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	load_map(t_mlxinfo *mlx)
{
	int		i;
	int		j;
	char	tile;

	i = -1;
	while (++i < mlx->map_info->height)
	{
		j = -1;
		while (++j < mlx->map_info->width)
		{
			tile = mlx->map_info->map_cont[i][j];
			if (tile == '0' || tile == 'P' || tile == 'C')
				mlx_image_to_window(mlx->mlx, mlx->empty, j * 64, i * 64);
			if (tile == 'C')
				mlx_image_to_window(mlx->mlx, mlx->collectible, j * 64, i * 64);
			else if (tile == '1')
				mlx_image_to_window(mlx->mlx, mlx->wall, j * 64, i * 64);
			else if (tile == 'E')
				mlx_image_to_window(mlx->mlx, mlx->exit, j * 64, i * 64);
		}
	}
	mlx_image_to_window(mlx->mlx, mlx->player, mlx->map_info->player_x * 64, \
		mlx->map_info->player_y * 64);
	mlx->moves = 0;
}

mlx_image_t	*mlx_tex_to_img(mlx_t *mlx, mlx_image_t *img, char *p)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(p);
	if (!mlx || !texture)
		return (NULL);
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		return (NULL);
	mlx_delete_texture(texture);
	return (img);
}

static t_mlxinfo	*mlx_initialize(t_map *map)
{
	t_mlxinfo		*mlx;

	mlx = (t_mlxinfo *)ft_calloc(sizeof(t_mlxinfo), 1);
	mlx->map_info = map;
	mlx->mlx = mlx_init(mlx->map_info->width * 64, mlx->map_info->height * 64, \
		"so long", false);
	if (!mlx || !mlx->mlx)
		return (NULL);
	mlx->wall = mlx_tex_to_img(mlx->mlx, mlx->wall, "textures/wall.png");
	mlx->collectible = mlx_tex_to_img(mlx->mlx, mlx->collectible, \
		"textures/collectible.png");
	mlx->empty = mlx_tex_to_img(mlx->mlx, mlx->empty, "textures/empty.png");
	mlx->exit = mlx_tex_to_img(mlx->mlx, mlx->exit, "textures/exit.png");
	mlx->player = mlx_tex_to_img(mlx->mlx, mlx->player, \
		"textures/player_f.png");
	if (!mlx->collectible || !mlx->empty || !mlx->exit || !mlx->player || \
		!mlx->wall)
		return (free_mlx(mlx), NULL);
	return (mlx);
}

int	main(int argc, char **argv)
{
	t_map			*map;
	t_mlxinfo		*mlx;
	char			*s;

	if ((argc != 2) || (!argv[1][0]))
		return (error_sl(NULL, 0), 1);
	s = ft_strrchr(argv[1], '/');
	if (s)
	{
		if (ft_strlen(s) < 6)
			return (error_sl(NULL, 0), 1);
	}
	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (1);
	if (!parse_map(argv[1], map))
		return (1);
	mlx = mlx_initialize(map);
	load_map(mlx);
	mlx_key_hook(mlx->mlx, &my_keyhook, mlx);
	mlx_loop(mlx->mlx);
	mlx_terminate(mlx->mlx);
	free(mlx);
	return (0);
}
