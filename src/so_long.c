/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:02:47 by ssandova          #+#    #+#             */
/*   Updated: 2024/09/12 17:01:09 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	if ((argc == 1)|| (!argv[1][0]))
		return (1);
//		return (error_sl(NULL, 1), 1);	
	mlx_t	*mlx;
	mlx = mlx_init(256, 256, "42", true);
	if (!mlx)
		return (1);
	// mlx_loop(mlx);
}
