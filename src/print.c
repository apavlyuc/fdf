/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vector2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:05:52 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/01/23 20:34:27 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_vector2(t_vector2 **vectors, int size)
{
	int	i;

	i = 0;
	printf("\n");
	while (i < size)
	{
		printf("vector #%d\t%p\nx = %f\ty = %f\n", i, ((*vectors + i)),
			((*vectors + i))->x, ((*vectors + i))->y);
		i++;
	}
}

void	print_vector3(t_vector3 ***vectors, int size)
{
	int	i;

	i = 0;
	printf("\n");
	while (i < size)
	{
		printf("vector #%d\t%p\nx = %d\ty = %d\tz = %f\n", i, (*(*vectors + i)),
			   (*(*vectors + i))->x, (*(*vectors + i))->y, (*(*vectors + i))->z);
		i++;
	}
}
