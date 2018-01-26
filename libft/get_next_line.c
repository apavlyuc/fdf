/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:52:48 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/01/19 09:07:12 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

static t_list		*get_current(t_list **list, const int fd)
{
	t_list			*temp;

	temp = *list;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(temp->content = ft_strnew(0)))
		return (NULL);
	temp->content_size = fd;
	ft_lstadd(list, temp);
	temp = *list;
	return (temp);
}

static int			strcpy_to(char **dst, char *src)
{
	int				i;

	free((void *)*dst);
	*dst = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	NULL_CHECK(dst);
	i = -1;
	while (*(src + ++i) != '\0' && *(src + i) != '\n')
		*(*dst + i) = *(src + i);
	*(*dst + i) = '\0';
	return (i);
}

static int			helper(char **line, t_list **current)
{
	int				i;
	char			*temp;
	int				len;

	if ((i = strcpy_to(line, (*current)->content)) == -1)
		return (0);
	len = (int)ft_strlen((*current)->content);
	if (i < len)
	{
		if (!(temp = ft_strsub((*current)->content, i + 1, len - i - 1)))
			return (0);
		free((void *)(*current)->content);
		if (!((*current)->content = ft_strjoin("", temp)))
			return (0);
		free((void *)temp);
	}
	else
	{
		ft_strclr((*current)->content);
		free((void *)(*current)->content);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*list;
	int				i;
	t_list			*current;
	char			*tmp;

	ERR_CHECK(fd, line, read(fd, buf, 0));
	NULL_CHECK((current = get_current(&list, fd)));
	NULL_CHECK((*line = ft_strnew(0)));
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = 0;
		NULL_CHECK((tmp = ft_strjoin(current->content, buf)));
		free((void *)current->content);
		current->content = ft_strdup(tmp);
		free((void *)tmp);
		BREAKER(ft_strchr(buf, '\n'));
	}
	END_CHECK(i, ft_strlen(current->content));
	NULL_CHECK(helper(line, &current));
	return (1);
}
