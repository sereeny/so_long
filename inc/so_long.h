#ifndef SO_LONG_H
#define so_LONG_H

# include "../libft/inc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

//structs

typedef	struct s_map
{
	char	**map;
	int		exit;
	int		collectibles;
	int		player;
	int 	player_x;
	int 	player_y;
}	t_map;

int		main(int argc, char **argv);

// parsing
int	parse_map(char *file, t_map *map);

//bool	parse_map(char *file);
//void	error_type(t_game game, int type);
//void	error_sl(t_game game, int type)

//utils

void	error_sl(t_map *game, int type);
int		ft_strlen_sl(char *str);

//int		ft_strlen_sl(char *str);

#endif