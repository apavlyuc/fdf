/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:13:12 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/03/10 02:03:17 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

static void		smlx_init(t_mlx *mlx, t_plane *plane)
{
	int			size;

	size = (plane->area) * 4;
	if (size > 2000)
		size = 2000;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, size, size, "fdf");
	mlx->img = mlx_new_image(mlx->mlx, size, size);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->sizel),
							&(mlx->endian));
	mlx->size = size;
	mlx->vec.angle = PI / 180 * 15;
}

static void		adapt_image(t_vector2 **vec2, int size)
{
	int			i;
	float		adapt_x;
	float		adapt_y;

	i = -1;
	adapt_x = 0;
	adapt_y = 0;
	while (++i < size)
	{
		if ((*vec2 + i)->x < 0 && (*vec2 + i)->x < adapt_x)
			adapt_x = (*vec2 + i)->x;
		if ((*vec2 + i)->y < 0 && (*vec2 + i)->y < adapt_y)
			adapt_y = (*vec2 + i)->y;
	}
	i = -1;
	while (++i < size)
	{
		(*vec2 + i)->x -= adapt_x;
		(*vec2 + i)->y -= adapt_y;
	}
}

static int		deal_key(int key, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	if (key == 53)
		esc_free(mlx);
	if (key == 34 || key == 31)
		zoom_handl(mlx, key);
	if (key == 126 || key == 125 || key == 123 || key == 124)
		move_handl(mlx, key);
	if (key == 69 || key == 78 || key == 75 || key == 67)
		color_handl(mlx, key);
	return (1);
}

int				main(int ac, char **av)
{
	t_mlx		mlx;
	float		*p;

	mlx.plane = is_valid(ac, av, &(mlx.vec.vec3));
	smlx_init(&mlx, mlx.plane);
	if (!(mlx.vec.vec2 =
		(t_vector2 *)malloc(sizeof(t_vector2) * mlx.plane->area)))
	{
		free(mlx.vec.vec3);
		plane_free(&mlx);
	}
	convert(&mlx, &(mlx.vec.vec2), &(mlx.vec.vec3));
	adapt_image(&(mlx.vec.vec2), (mlx.plane)->area);
	if (!(p = write_image(&mlx, &mlx.vec, mlx.plane)))
		esc_free(&mlx);
	else
		free(p);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	show_keys(&mlx);
	mlx_hook(mlx.win, 2, (1L << 0), &deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
