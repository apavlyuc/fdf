/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:35:53 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/30 14:50:10 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*ref;

	i = -1;
	ref = (unsigned char *)s;
	while (++i < (int)n)
		if (*(ref + i) == (unsigned char)c)
			return ((void *)(ref + i));
	return (NULL);
}
