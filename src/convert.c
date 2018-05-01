/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:36:47 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/03/07 21:49:11 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		update_vec3(t_mlx *mlx, t_vector2 **vec2, t_vector3 **vec3)
{
	int		i;
	double	cs;
	double	sn;

	i = -1;
	cs = cos(mlx->vec.angle);
	sn = sin(mlx->vec.angle);
	while (++i < mlx->plane->area)
	{
		(*vec3 + i)->z = ((*vec3 + i)->z * cs - (*vec3 + i)->y *
		sn) * cs + (*vec3 + i)->x * sn;
		(*vec3 + i)->x = (*vec2 + i)->x;
		(*vec3 + i)->y = (*vec2 + i)->y;
		(*vec2 + i)->color = (*vec3 + i)->color;
	}
}

int			convert(t_mlx *mlx, t_vector2 **vec2, t_vector3 **vec3)
{
	int		i;
	double	cs;
	double	sn;

	i = -1;
	cs = cos(mlx->vec.angle);
	sn = sin(mlx->vec.angle);
	while (++i < mlx->plane->area)
	{
		(*vec2 + i)->x = ((*vec3 + i)->x * cs - ((*vec3 + i)->z *
		cs - (*vec3 + i)->y * sn) * sn) * cs + ((*vec3 + i)->y * cs +
		(*vec3 + i)->z * sn) * sn;
		(*vec2 + i)->y = ((*vec3 + i)->y * cs + (*vec3 + i)->z * sn)
		* cs - ((*vec3 + i)->x * cs - ((*vec3 + i)->z * cs - (*vec3 +
		i)->y * sn) * sn) * sn;
	}
	update_vec3(mlx, vec2, vec3);
	return (1);
}
