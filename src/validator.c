/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:12:59 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/03/10 01:29:06 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int		fill_vec3(char *line, t_vector3 **vec3, t_plane *plane)
{
	static int	i = 0;
	int			j;
	char		**arr;
	char		*p;

	if (!(arr = ft_strsplit(line, ' ')))
		return (0);
	j = -1;
	while (++j < plane->colums)
	{
		(*vec3 + i)->x = j;
		(*vec3 + i)->y = i / plane->colums;
		(*vec3 + i)->z = ft_atof(arr[j]);
		if ((p = ft_strchr(arr[j], ',')))
			(*vec3 + i)->color = ft_atoi(p + 1);
		else
			(*vec3 + i)->color = 0x009400d3;
		free(arr[j]);
		i++;
	}
	free(arr);
	return (1);
}

static int		read_cycle(char **line, int fd, t_vector3 **vec3, t_plane *pl)
{
	int			i;
	int			ret;

	i = 0;
	while (++i < pl->rows)
	{
		free(*line);
		if ((ret = get_next_line(fd, line)) != -1
			&& pl->colums == words_count(*line, ' '))
		{
			if (!fill_vec3(*line, vec3, pl))
			{
				free(*line);
				return (0);
			}
		}
		else
		{
			if (ret != -1)
				free(*line);
			return (0);
		}
	}
	free(*line);
	return (1);
}

static t_plane	*read_vec3(char *file_name, t_vector3 **vec3, t_plane *plane)
{
	char		*line;
	int			fd;

	if (((*plane).rows = ft_linecount(file_name)) <= 0 ||
		(fd = open(file_name, O_RDONLY)) == -1 || get_next_line(fd, &line) <= 0)
		return (NULL);
	(*plane).colums = words_count(line, ' ');
	(*plane).area = (*plane).rows * (*plane).colums;
	if (!(*vec3 = (t_vector3 *)malloc(sizeof(t_vector3) * (*plane).area)))
		return (NULL);
	if (!fill_vec3(line, vec3, plane) || !read_cycle(&line, fd, vec3, plane))
	{
		free(*vec3);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (plane);
}

t_plane			*is_valid(int ac, char **av, t_vector3 **vec3)
{
	t_plane		*plane;

	if (ac != 2 || !av)
	{
		ft_putstr("usage: fdf map_file\n");
		exit(-1);
	}
	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!(plane = read_vec3(av[1], vec3, plane)))
	{
		free(plane);
		exit(-1);
	}
	return (plane);
}
