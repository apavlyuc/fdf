/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:25:28 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/01/26 19:53:43 by apavlyuc         ###   ########.fr       */
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

void			writer(void *mlx, void *win, t_vector3 ***vec3, t_plane *plane, float angle)
{
	int			i;
	t_vector2	*vec2;
	float		*arr;

	convert(&vec2, vec3, plane->rows * plane->colums + 1, angle);
	arr = (float *)malloc(sizeof(float) * 4);
	i = -1;
	while (++i < plane->rows * plane->colums)
	{
		arr[0] = vec2[i].x;
		arr[1] = vec2[i].y;
		if (i % plane->colums != plane->colums - 1)
		{
			insert_pair(&arr, vec2[i + 1].x, vec2[i + 1].y);
			drow_line(mlx, win, arr);
		}
		arr[0] = vec2[i].x;
		arr[1] = vec2[i].y;
		if (i / plane->colums != plane->rows - 1)
		{
			insert_pair(&arr, vec2[i + plane->colums].x, vec2[i + plane->colums].y);
			drow_line(mlx, win, arr);
		}
	}
	free(arr);
}
