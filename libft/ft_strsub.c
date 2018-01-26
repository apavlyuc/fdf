/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:08:53 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/30 19:26:33 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*string;
	int		i;

	if (!s || start + len > ft_strlen(s))
		return (NULL);
	i = -1;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	while (++i < (int)len)
		*(string + i) = *(s + start + i);
	*(string + i) = '\0';
	return (string);
}
