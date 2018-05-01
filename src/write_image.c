/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:25:28 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/03/10 01:41:52 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

static void		insert_pair2(float **arr, float x, float y)
{
	(*arr)[2] = x;
	(*arr)[3] = y;
}

static void		insert_pair1(float **arr, float x, float y)
{
	(*arr)[0] = x;
	(*arr)[1] = y;
}

static void		drow_if_in_wind(t_mlx *mlx, float *arr, int color)
{
	if ((arr[0] < mlx->size && arr[0] > 0 &&
		arr[1] < mlx->size && arr[1] > 0) ||
		(arr[2] < mlx->size && arr[2] > 0 &&
		arr[3] < mlx->size && arr[3] > 0))
		drow_line(mlx, arr, color);
}

float			*write_image(t_mlx *mlx, t_vectors *vec, t_plane *pl)
{
	int			i;
	float		*arr;

	IS_NULL((arr = (float *)malloc(sizeof(float) * 4)));
	i = -1;
	while (++i < pl->area)
	{
		insert_pair1(&arr, (vec->vec2)[i].x, (vec->vec2)[i].y);
		if (i % pl->colums != pl->colums - 1)
		{
			insert_pair2(&arr, (vec->vec2)[i + 1].x, (vec->vec2)[i + 1].y);
			drow_if_in_wind(mlx, arr, (vec->vec2)[i].color);
			insert_pair1(&arr, (vec->vec2)[i].x, (vec->vec2)[i].y);
		}
		if (i / pl->colums != pl->rows - 1)
		{
			insert_pair2(&arr, (vec->vec2)[i + pl->colums].x,
						(vec->vec2)[i + pl->colums].y);
			drow_if_in_wind(mlx, arr, (vec->vec2)[i].color);
			insert_pair1(&arr, (vec->vec2)[i].x, (vec->vec2)[i].y);
		}
		else if (i % pl->colums == pl->colums - 1)
			put_pixel(mlx, arr[0], arr[1], (vec->vec2)[i].color);
	}
	return (arr);
}
