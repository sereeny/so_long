/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:02:47 by ssandova          #+#    #+#             */
/*   Updated: 2024/09/06 16:33:27 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	if ((argc != 2)|| (!argv[1][0]) || (parse_file(argv[1]) == false))
		return (ft_printf("Error\n"), 1);
		
	// void	*mlx;
	// void	*win;

	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 1920, 1080);
	// mlx_loop(mlx);
}
