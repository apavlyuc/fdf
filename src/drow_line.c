/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:24:13 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/03/05 18:38:47 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../libft/libft.h"
#include "fdf.h"

static void		swap(float *a, float *b)
{
	float		p;

	p = *a;
	*a = *b;
	*b = p;
}

static void		swaper(float **arr, int *steep)
{
	float		a;
	float		b;

	*steep = 0;
	a = *(*arr) - *(*arr + 2);
	b = *(*arr + 1) - *(*arr + 3);
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	if (a < b)
	{
		swap(*arr, *arr + 1);
		swap(*arr + 2, *arr + 3);
		*steep = 1;
	}
	if (*(*arr) > *(*arr + 2))
	{
		swap(*arr, *arr + 2);
		swap(*arr + 1, *arr + 3);
	}
}
static void		put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int			x1;
	int			y1;

	x1 = x * mlx->bpp / 8;
	y1 = y * mlx->sizel;
	if ((x1 + y1) < mlx->size * mlx->sizel &&
		(x1 + y1) > 0 && x < mlx->size && x > 0 &&
		y < mlx->size && y > 0)
		*(int *)(mlx->addr + x1 + y1) =
			mlx_get_color_value(mlx->mlx, color);
}

void			drow_line(t_mlx *mlx, float *arr, int color)
{
	int			steep;
	float		d[2];
	float		err[2];
	float		tmp[2];

	swaper(&arr, &steep);
	d[0] = arr[2] - arr[0];
	d[1] = arr[3] - arr[1];
	err[1] = ((d[1] < 0) ? -d[1] : d[1]) * 2;
	err[0] = 0;
	tmp[1] = arr[1];
	tmp[0] = arr[0] - 1;
	while (++(tmp[0]) < arr[2])
	{
		if (steep)
			put_pixel(mlx, tmp[1], tmp[0], color);
		else
			put_pixel(mlx, tmp[0], tmp[1], color);
		err[0] += err[1];
		if (err[0] > d[0])
		{
			tmp[1] += (arr[3] > arr[1] ? 1 : -1);
			err[0] -= d[0] * 2;
		}
	}
}
