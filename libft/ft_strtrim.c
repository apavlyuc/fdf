/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:45:07 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/12/03 20:28:17 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_whtspace(char c)
{
	return ((c == ' ' || c == '\n' || c == '\t') ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;

	if (!s)
		return (NULL);
	while (is_whtspace(*s))
		s++;
	i = 0;
	j = 0;
	while (*(s + i))
		if (!is_whtspace(*(s + i++)) && (is_whtspace(*(s + i)) ||
										*(s + i) == '\0'))
			j = i;
	return (ft_strsub(s, 0, j));
}
