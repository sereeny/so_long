/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:44:15 by ssandova          #+#    #+#             */
/*   Updated: 2024/10/07 17:49:48 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

//structs

typedef struct s_map
{
	char		**map_cont;
	char		**map_copy;
	int			width;
	int			height;
	int			exit;
	int			collectibles;
	int			player;
	int			player_x;
	int			player_y;
}	t_map;

typedef struct s_mlxinfo
{
	mlx_t		*mlx;
	mlx_image_t	*wall;
	mlx_image_t	*empty;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	t_map		*map_info;
}	t_mlxinfo;

int		main(int argc, char **argv);

//play
void	my_keyhook(mlx_key_data_t keydata, void* param);

// parsing

int		parse_map(char *file, t_map *map);
void	update_position(t_map *map, int x, int y);
void	flood_fill(t_map *map, int x, int y);

//utils

void	error_sl(t_map *game, int type);
void	free_game(char **map, t_map *game);
void	free_mlx(t_mlxinfo *mlx);


#endif
