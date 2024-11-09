/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:34:03 by ssandova          #+#    #+#             */
/*   Updated: 2024/11/09 11:36:48 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	mlx_image_t	*enemy;
	mlx_image_t	*player;
	mlx_image_t	*text;
	t_map		*map_info;
	int			moves;
}	t_mlxinfo;

int		main(int argc, char **argv);

//play
void		my_keyhook_b(mlx_key_data_t keydata, void* param);
mlx_image_t	*mlx_tex_to_img(mlx_t *mlx, mlx_image_t *img, char *p);

// parsing

int		parse_map_bonus(char *file, t_map *map);
void	update_position(t_map *map, int x, int y);
void	flood_fill_bonus(t_map *map, int x, int y);
int		check_tokens(t_map *map);

//utils

void	error_sl(t_map *game, int type);
void	free_map(char **map, int height);
void	free_mlx(t_mlxinfo *mlx);


#endif
