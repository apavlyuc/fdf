/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:13:12 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/03/05 21:02:34 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

static void		smlx_init(t_mlx *mlx, t_plane *plane)
{
	int			size;

	size = (plane->rows * plane->colums + 1) * 4;
	if (size > 2000)
		size = 2000;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, size, size, "fdf");
	mlx->img = mlx_new_image(mlx->mlx, size, size);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->sizel), &(mlx->endian));
	mlx->size = size;
}

static void		adapt_image(t_vector2 **vec2, int size)
{
	int			i;
	float		adapt_x;
	float		adapt_y;

	i = -1;
	adapt_x = 0;
	adapt_y = 0;
	while (++i < size - 1)
	{
		if ((*vec2 + i)->x < 0 && (*vec2 + i)->x < adapt_x)
			adapt_x = (*vec2 + i)->x;
		if ((*vec2 + i)->y < 0 && (*vec2 + i)->y < adapt_y)
			adapt_y = (*vec2 + i)->y;
	}
	i = -1;
	while (++i < size - 1)
	{
		(*vec2 + i)->x -= adapt_x;
		(*vec2 + i)->y -= adapt_y;
	}
}
int		deal_key(int key, void *param)
{
	t_vectors	*vec;

	vec = (t_vectors *)param;
	if (key == 53)
	{
		exit(1);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_vectors	vec;
	t_mlx		mlx;
	
	mlx.plane = is_valid(ac, av, &(vec.vec3));
	smlx_init(&mlx, mlx.plane);
	convert(&(vec.vec2), &(vec.vec3), (mlx.plane)->rows * (mlx.plane)->colums + 1, PI / 180 * 15);
	adapt_image(&(vec.vec2), (mlx.plane)->rows * (mlx.plane)->colums + 1);
	write_image(&mlx, &vec, mlx.plane);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);	
	mlx_key_hook(mlx.win, &deal_key, (void *)(&vec));
	mlx_loop(mlx.mlx);
	return (0);
}
