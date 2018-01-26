/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:13:12 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/01/26 19:44:34 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

int				main(int ac, char **av)
{
	t_vector3	**vec3;
	int			size;
	void		*mlx_ptr;
	void		*win_ptr;
	t_plane		*plane;

	plane = is_valid(ac, av, &vec3);
	size = plane->rows * plane->colums + 1;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "fdf");
	writer(mlx_ptr, win_ptr, &vec3, plane, PI / 180 * 15);
	mlx_loop(mlx_ptr);
	return (0);
}
