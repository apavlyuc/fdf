/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 01:47:13 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/24 06:05:33 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*string;
	int		i;

	i = -1;
	if (s && f)
	{
		string = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!string)
			return (NULL);
		while (*(s + ++i) != '\0')
			*(string + i) = f(*(s + i));
		*(string + i) = '\0';
		return (string);
	}
	return (NULL);
}
