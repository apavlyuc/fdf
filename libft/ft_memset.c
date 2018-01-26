/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:40:06 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/30 14:51:31 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*ref;

	i = -1;
	ref = (unsigned char *)b;
	while (++i < (int)len)
		*(ref + i) = (unsigned char)c;
	return (b);
}
