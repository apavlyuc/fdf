/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:13:12 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/02/19 20:23:22 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

void			smlx_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1200, 1200, "fdf");
	mlx->img = mlx_new_image(mlx->mlx, 1200, 1200);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->sizel), &(mlx->endian));
}

int				main(int ac, char **av)
{
	t_vector3	**vec3;
	int			size;
	t_plane		*plane;
	t_mlx		mlx;

	printf("falid?\n");
	plane = is_valid(ac, av, &vec3);
	printf("valid\n");
	size = plane->rows * plane->colums + 1;
	smlx_init(&mlx);
	writer(&mlx, &vec3, plane, PI / 180 * 15);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
