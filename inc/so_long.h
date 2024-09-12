#ifndef SO_LONG_H
#define so_LONG_H

# include "../libft/inc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

//struct
typedef struct s_game
{
	void	*window;
	void	*context;
	int32_t	width;
	int32_t	height;
	double	delta_time;
}	t_game;


int		main(int argc, char **argv);

// parsing

//bool	parse_map(char *file);
//void	error_type(t_game game, int type);
//void	error_sl(t_game game, int type)

//utils

//int		ft_strlen_sl(char *str);

#endif