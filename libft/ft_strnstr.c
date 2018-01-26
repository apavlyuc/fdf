/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:02:20 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/30 16:42:07 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *h, const char *n, size_t l)
{
	size_t	needle_len;
	int		len;
	int		i;

	needle_len = ft_strlen(n);
	if (needle_len == 0)
		return ((char *)h);
	len = (int)(l - needle_len);
	i = -1;
	while (*(h + ++i) && len-- >= 0)
		if (!ft_memcmp(h + i, n, needle_len))
			return ((char *)(h + i));
	return (NULL);
}
