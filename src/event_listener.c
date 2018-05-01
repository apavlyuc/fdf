/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:16:46 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/03/10 02:05:25 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

static void	img_recreat(t_mlx *mlx)
{
	float	*p;

	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, mlx->size, mlx->size);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->sizel),
							&(mlx->endian));
	if (!(p = write_image(mlx, &(mlx->vec), mlx->plane)))
		esc_free(mlx);
	else
		free(p);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	show_keys(mlx);
}

void		zoom_handl(t_mlx *mlx, int key)
{
	int		i;
	float	step;

	i = -1;
	step = mlx->size / 2;
	while (++i < mlx->plane->area)
	{
		if (key == 31)
		{
			(mlx->vec.vec2 + i)->x += (step - (mlx->vec.vec2 + i)->x) / 20;
			(mlx->vec.vec2 + i)->y += (step - (mlx->vec.vec2 + i)->y) / 20;
		}
		else
		{
			(mlx->vec.vec2 + i)->x -= (step - (mlx->vec.vec2 + i)->x) / 20;
			(mlx->vec.vec2 + i)->y -= (step - (mlx->vec.vec2 + i)->y) / 20;
		}
	}
	img_recreat(mlx);
}

void		move_handl(t_mlx *mlx, int key)
{
	int		i;
	float	step;

	step = mlx->size / 50;
	i = -1;
	while (++i < mlx->plane->area)
	{
		if (key == 125)
			(mlx->vec.vec2 + i)->y += step;
		if (key == 126)
			(mlx->vec.vec2 + i)->y -= step;
		if (key == 123)
			(mlx->vec.vec2 + i)->x -= step;
		if (key == 124)
			(mlx->vec.vec2 + i)->x += step;
	}
	img_recreat(mlx);
}

void		color_handl(t_mlx *mlx, int key)
{
	int		i;
	int		color_step;

	i = -1;
	if (key == 78)
		color_step = -1 * 0x000000F0;
	else if (key == 69)
		color_step = 0x000000F0;
	else if (key == 75)
		color_step = -1 * 0x0000F000;
	else if (key == 67)
		color_step = 0x0000F000;
	while (++i < mlx->plane->area)
		(mlx->vec.vec2 + i)->color += color_step;
	img_recreat(mlx);
}

void		show_keys(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 15, 15, 0x00FFFFFF,
	"ESC : exit;");
	mlx_string_put(mlx->mlx, mlx->win, 15, 30, 0x00FFFFFF,
	"I : zoom in;  O : zoom out;");
	mlx_string_put(mlx->mlx, mlx->win, 15, 45, 0x00FFFFFF,
	"Arrows : move;");
	mlx_string_put(mlx->mlx, mlx->win, 15, 60, 0x00FFFFFF,
	"+ : up color_step;  - : down color_step");
	mlx_string_put(mlx->mlx, mlx->win, 15, 75, 0x00FFFFFF,
	"* : up color_jump;  / : down color_jump");
}
