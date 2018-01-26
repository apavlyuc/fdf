/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linecount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:16:00 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/01/19 11:30:43 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int			ft_linecount(char *file_name)
{
	int		count;
	int		fd;
	char	buf[1];

	if (!file_name || (fd = open(file_name, O_RDONLY)) == -1)
		return (-1);
	if (read(fd, buf, 0) != 0)
	{
		close(fd);
		return (-1);
	}
	count = 0;
	while (read(fd, buf, 1))
		if (buf[0] == '\n')
			count++;
	if (count == 0)
		count = 1;
	close(fd);
	return (count);
}
