/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:25:00 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/03/10 01:46:26 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define PI 3.14159265359
# define IS_ERR3(x, y, z) if (x <= 0 || y == -1 || z == (float)-1) return (-1);
# define IS_ERR1(x) if (x == -1) return (-1);
# define IS_NULL(x) if (x == NULL) return (NULL);

typedef struct	s_vector3
{
	float		z;
	int			x;
	int			y;
	int			color;
}				t_vector3;

typedef struct	s_vector2
{
	float		x;
	float		y;
	int			color;
}				t_vector2;

typedef struct	s_vectors
{
	t_vector3	*vec3;
	t_vector2	*vec2;
	float		angle;
}				t_vectors;

typedef struct	s_plane
{
	int	rows;
	int	colums;
	int	area;
}				t_plane;

typedef struct	s_mlx
{
	int			endian;
	int			bpp;
	char		*addr;
	void		*mlx;
	void		*win;
	void		*img;
	int			sizel;
	t_plane		*plane;
	int			size;
	t_vectors	vec;
}				t_mlx;

int				convert(t_mlx *mlx, t_vector2 **vec2, t_vector3 **vec3);
void			update_vec3(t_mlx *mlx, t_vector2 **vec2, t_vector3 **vec3);

t_plane			*is_valid(int ac, char **av, t_vector3 **vec3);

float			*write_image(t_mlx *mlx, t_vectors *vec, t_plane *plane);
void			drow_line(t_mlx *mlx, float *arr, int color);
void			put_pixel(t_mlx *mlx, int x, int y, int color);
void			show_keys(t_mlx *mlx);

void			zoom_handl(t_mlx *mlx, int key);
void			move_handl(t_mlx *mlx, int key);
void			color_handl(t_mlx *mlx, int key);

void			esc_free(t_mlx *mlx);
void			plane_free(t_mlx *mlx);

#endif
