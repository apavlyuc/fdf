
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:36:47 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/03/05 19:44:05 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

static void	free_vec3(t_vector3 ***vec3, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		free(*(*vec3 + i));
	}
}

void		convert(t_vector2 **vec2, t_vector3 ***vec3, int size, float angle)
{
	int		i;

	i = -1;
	if (!(*vec2 = (t_vector2 *)malloc(sizeof(t_vector2) * size)))
	{
		free_vec3(vec3, size);
		exit(-1);
	}
	while (++i < size - 1)
	{
		(*vec2 + i)->x = (((*(*vec3 + i))->x * cos(angle) - ((*(*vec3 +
		i))->z * cos(angle) - (*(*vec3 + i))->y * sin(angle)) * sin(angle))
		* cos(angle) + ((*(*vec3 + i))->y * cos(angle) + (*(*vec3 + i))->z *
		sin(angle)) * sin(angle));
		(*vec2 + i)->y = (((*(*vec3 + i))->y * cos(angle) + (*(*vec3 +
		i))->z * sin(angle)) * cos(angle) - ((*(*vec3 + i))->x * cos(angle)
		- ((*(*vec3 + i))->z * cos(angle) - (*(*vec3 + i))->y * sin(angle)) *
		sin(angle)) * sin(angle));
		(*(*vec3 + i))->z = ((*(*vec3 + i))->z * cos(angle) - (*(*vec3 +
		i))->y * sin(angle)) * cos(angle) + (*(*vec3 + i))->x * sin(angle);
		(*(*vec3 + i))->x = (*vec2 + i)->x;
		(*(*vec3 + i))->y = (*vec2 + i)->y;
		(*vec2 + i)->color = (*(*vec3 + i))->color;
	}
}
