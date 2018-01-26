/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:46:26 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/12/03 21:12:57 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ref1;
	unsigned char	*ref2;

	i = -1;
	ref1 = (unsigned char *)s1;
	ref2 = (unsigned char *)s2;
	while (++i < n)
		if (*(ref1 + i) != *(ref2 + i))
			return (*(ref1 + i) - *(ref2 + i));
	return (0);
}
