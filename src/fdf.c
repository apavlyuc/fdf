/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:13:12 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/02/13 15:48:01 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

void			smlx_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1000, 1000, "fdf");
	*(mlx->bpp) = 32;
	*(mlx->sizel) = 1000 * *(mlx->bpp);
	*(mlx->endian) = 0;
	mlx->img = mlx_new_image(mlx->mlx, 0, 0);
	mlx->addr = mlx_get_data_addr(mlx->img, mlx->bpp, mlx->sizel, mlx->endian);
}

int				main(int ac, char **av)
{
	t_vector3	**vec3;
	int			size;
	t_plane		*plane;
	t_mlx		mlx;

	plane = is_valid(ac, av, &vec3);
	size = plane->rows * plane->colums + 1;
	smlx_init(&mlx);
	/*
	int endian = 0;
	int bpp = 1;
	int sizel = 1000 *bpp;
	void *img = mlx_new_image(mlx.mlx, 500, 500);
	char *addr= mlx_get_data_addr(img, &bpp, &sizel, &endian);
	for (int i = 0; i < 100; i++)
	{
		*(int *)(addr + i)= 0x00663366;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img, 500, 500);*/
	writer(&mlx, &vec3, plane, PI / 180 * 30);
	mlx_loop(mlx.mlx);
	return (0);
}
