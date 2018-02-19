/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:25:28 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/02/19 20:08:59 by apavlyuc         ###   ########.fr       */
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

void			writer(t_mlx *mlx, t_vector3 ***vec3, t_plane *pl, float angle)
{
	int			i;
	t_vector2	*vec2;
	float		*arr;

	print_vector3(vec3, pl->rows * pl->colums);
	convert(&vec2, vec3, pl->rows * pl->colums + 1, angle);
	arr = (float *)malloc(sizeof(float) * 4);
	i = -1;
	print_vector2(&vec2, pl->rows * pl->colums);
	while (++i < pl->rows * pl->colums && arr)
	{
		arr[0] = vec2[i].x;
		arr[1] = vec2[i].y;
		if (i % pl->colums != pl->colums - 1)
		{
			insert_pair(&arr, vec2[i + 1].x, vec2[i + 1].y);
			drow_line(mlx, arr);
		}
		arr[0] = vec2[i].x;
		arr[1] = vec2[i].y;
		if (i / pl->colums != pl->rows - 1)
		{
			insert_pair(&arr, vec2[i + pl->colums].x, vec2[i + pl->colums].y);
			drow_line(mlx, arr);
		}
	}
	free(arr);
}
