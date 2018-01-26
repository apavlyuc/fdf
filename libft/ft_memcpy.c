/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:50:44 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/30 14:50:39 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*ref1;
	unsigned char	*ref2;

	i = -1;
	ref1 = (unsigned char *)dst;
	ref2 = (unsigned char *)src;
	while (++i < (int)n)
		*(ref1 + i) = *(ref2 + i);
	return (dst);
}
