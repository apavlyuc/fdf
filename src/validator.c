/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:12:59 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/02/13 11:36:27 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void		fill_vec3(char *line, t_vector3 ***vec3, int n, int parts)
{
	static int	i;
	int			j;
	char		**arr;

	if (!(arr = ft_strsplit(line, ' ')))
		exit(-1);
	if (n == -1)
		i = 0;
	j = -1;
	while (++j < parts)
	{
		(*(*vec3 + i))->x = j;
		(*(*vec3 + i))->y = i / parts;
		(*(*vec3 + i))->z = atof(arr[j]);
		free(arr[j]);
		i++;
	}
	free(arr);
}

static void		read_cycle(char **line, int fd, t_vector3 ***vec3, int lines)
{
	int			i;
	int			ret;
	int			parts;

	i = 0;
	parts = words_count(*line, ' ');
	while (++i < lines)
	{
		free(*line);
		if ((ret = get_next_line(fd, line)) != -1
			&& parts == words_count(*line, ' '))
			fill_vec3(*line, vec3, i, parts);
		else
		{
			i = -1;
			while (++i < lines * parts)
				free((*vec3)[i]);
			free(*vec3);
			if (ret != -1)
				free(*line);
			exit(-1);
		}
	}
	free(*line);
}

static void		*free_iter(t_vector3 ***vec3, int i)
{
	while (--i >= 0)
		free((*vec3)[i]);
	return (NULL);
}

static t_plane	*read_vec3(char *file_name, t_vector3 ***vec3, t_plane *plane)
{
	char		*line;
	int			lines;
	int			parts;
	int			fd;
	int			i;

	if ((lines = ft_linecount(file_name)) <= 0 ||
		(fd = open(file_name, O_RDONLY)) == -1 || get_next_line(fd, &line) <= 0)
		return (NULL);
	parts = words_count(line, ' ');
	if (!(*vec3 = (t_vector3 **)malloc(sizeof(t_vector3 *)
									* (parts * lines + 1))))
		return (NULL);
	(*vec3)[parts * lines] = NULL;
	i = -1;
	while (++i < parts * lines)
		if (!((*vec3)[i] = (t_vector3 *)malloc(sizeof(t_vector3))))
			return (free_iter(vec3, i));
	fill_vec3(line, vec3, -1, parts);
	read_cycle(&line, fd, vec3, lines);
	close(fd);
	(*plane).rows = lines;
	(*plane).colums = parts;
	return (plane);
}

t_plane			*is_valid(int ac, char **av, t_vector3 ***vec3)
{
	t_plane		*plane;

	if (ac != 2 || !av)
	{
		ft_putstr("usage: fdf map_file\n");
		exit(-1);
	}
	if (!vec3)
		exit(-1);
	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!(plane = read_vec3(av[1], vec3, plane)))
	{
		free(plane);
		exit(-1);
	}
	return (plane);
}
