/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandova <ssandova@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:02:47 by ssandova          #+#    #+#             */
/*   Updated: 2024/10/05 11:22:53 by ssandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <errno.h>

void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	mlx_t	*mlx;

	if ((argc != 2) || (!argv[1][0]))
		return (error_sl(NULL, 0), 1);
	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (1);
	if (parse_map(argv[1], map))
		return (1);
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(256, 256, "42", true);
	if (!mlx)
		return (1);
	// mlx_image_t *img = mlx_new_image(mlx, 256, 256);
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_texture_t *a = mlx_load_png("/home/ssandova/Desktop/cursus/so_long/src/wall.png");
	if (!a)
	{
		printf("%s", mlx_strerror(mlx_errno));
		return 0;
	}

	mlx_image_t *img = mlx_texture_to_image(mlx, a);


	int i = mlx_image_to_window(mlx, img, 100, 100);
	ft_printf("%i", i);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
