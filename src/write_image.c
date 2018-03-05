/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:25:28 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/03/05 19:56:25 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "mlx.h"
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

static void		insert_pair(float **arr, float x, float y)
{
	(*arr)[2] = x;
	(*arr)[3] = y;
}

void			write_image(t_mlx *mlx, t_vectors *vec, t_plane *pl)
{
	int			i;
	float		*arr;

//	convert(&(vec->vec2), &(vec->vec3), pl->rows * pl->colums + 1, angle);
	arr = (float *)malloc(sizeof(float) * 4);
	i = -1;
	while (++i < pl->rows * pl->colums && arr)
	{
		arr[0] = (vec->vec2)[i].x;
		arr[1] = (vec->vec2)[i].y;
		if (i % pl->colums != pl->colums - 1)
		{
			insert_pair(&arr, (vec->vec2)[i + 1].x, (vec->vec2)[i + 1].y);
			drow_line(mlx, arr, (vec->vec2)[i].color);
		}
		arr[0] = (vec->vec2)[i].x;
		arr[1] = (vec->vec2)[i].y;
		if (i / pl->colums != pl->rows - 1)
		{
			insert_pair(&arr, (vec->vec2)[i + pl->colums].x, (vec->vec2)[i + pl->colums].y);
			drow_line(mlx, arr, (vec->vec2)[i].color);
		}/*
		else
			*(int *)(mlx->addr + (int)arr[0] * mlx->bpp / 8 + (int)arr[1] * mlx->sizel) =
			mlx_get_color_value(mlx->mlx, 0x000035d4);*/
	}
	free(arr);
}
