/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:23:40 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/03/07 18:39:01 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

void	esc_free(t_mlx *mlx)
{
	free(mlx->vec.vec2);
	free(mlx->vec.vec3);
	free(mlx->plane);
	exit(1);
}

void	plane_free(t_mlx *mlx)
{
	free(mlx->plane);
	exit(1);
}
