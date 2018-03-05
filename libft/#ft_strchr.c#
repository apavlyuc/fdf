/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:22:29 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/30 15:25:35 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*ref;
	int		i;

	i = -1;
	ref = (char *)s;
	while (*(ref + ++i) != '\0' || c == 0)
		if (*(ref + i) == c)
			return (ref + i);
	return (NULL);
}
