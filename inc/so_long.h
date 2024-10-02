/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:44:15 by ssandova          #+#    #+#             */
/*   Updated: 2024/10/02 16:35:40 by ssandova         ###   ########.fr       */
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

int		main(int argc, char **argv);

// parsing

int		parse_map(char *file, t_map *map);
void	update_position(t_map *map, int x, int y);
void	flood_fill(t_map *map, int x, int y);

//bool	parse_map(char *file);

//utils

void	error_sl(t_map *game, int type);
void	free_map(char **map, t_map *game);


#endif
