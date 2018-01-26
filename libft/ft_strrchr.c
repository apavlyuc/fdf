/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:35:39 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/24 01:06:12 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ref;

	ref = (char *)s;
	i = ft_strlen(s) + 1;
	while (--i != -1)
		if (*(ref + i) == c)
			return (ref + i);
	return (NULL);
}
