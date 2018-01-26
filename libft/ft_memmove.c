/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:13:27 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/30 17:06:55 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ref1;
	unsigned char	*ref2;

	ref1 = (unsigned char *)dst;
	ref2 = (unsigned char *)src;
	if ((unsigned long int)dst < (unsigned long int)src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			*(ref1 + len) = *(ref2 + len);
	return (dst);
}
