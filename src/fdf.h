/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:25:00 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/02/13 15:32:40 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define PI 3.14159265359
# define IS_ERR3(x, y, z) if (x <= 0 || y == -1 || z == (float)-1) return (-1);
# define IS_ERR1(x) if (x == -1) return (-1);

typedef struct	s_vector3
{
	int		x;
	int		y;
	float	z;
}				t_vector3;
typedef struct	s_vector2
{
	float x;
	float y;
}				t_vector2;
typedef struct	s_plane
{
	int rows;
	int colums;
}				t_plane;
typedef struct	s_mlx
{
	int		*endian;
	int		*bpp;
	int		*sizel;
	char	*addr;
	void	*mlx;
	void	*win;
	void	*img;
}				t_mlx;

/*
**		file: print.c
*/
void			print_vector2(t_vector2 **vectors, int size);
void			print_vector3(t_vector3 ***vectors, int size);

void			convert(t_vector2 **vec, t_vector3 ***v3, int size, float a);
/*
**		file: validator.c
*/
t_plane			*is_valid(int ac, char **av, t_vector3 ***vec3);

void			writer(t_mlx *mlx, t_vector3 ***v3, t_plane *plane, float a);
void			drow_line(void *mlx, void *win, float *arr);

#endif
