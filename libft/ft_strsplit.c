/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:23:31 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/12/03 18:35:26 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	get_count(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (*(s + i) != '\0')
	{
		while (*(s + i) == c)
			i++;
		if (*(s + i) != '\0')
			count++;
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
	}
	return (count);
}

static int	get_length(char const *s, char c)
{
	int		length;

	length = 0;
	while (*s != c && *s++ != '\0')
		length++;
	return (length);
}

static void	deleter(char **box)
{
	while (*box)
	{
		ft_strdel(box);
		box++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		parts;
	int		length;
	char	**box;

	if (!s || c == '\0' || !(box = (char **)malloc(sizeof(char *) * \
											((parts = get_count(s, c)) + 1))))
		return (NULL);
	i = 0;
	while (i < parts)
	{
		while (*s == c)
			s++;
		length = get_length(s, c);
		box[i] = ft_strsub(s, 0, length);
		if (!box[i++])
		{
			deleter(box);
			ft_strdel((char **)&box);
			return (NULL);
		}
		s += length;
	}
	box[i] = 0;
	return (box);
}
