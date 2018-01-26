/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:38:30 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/30 14:49:46 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*ref1;
	unsigned char	*ref2;

	i = -1;
	ref1 = (unsigned char *)dst;
	ref2 = (unsigned char *)src;
	while (++i < (int)n)
	{
		*(ref1 + i) = *(ref2 + i);
		if (*(ref1 + i) == (unsigned char)c)
			return (dst + ++i);
	}
	return (NULL);
}
