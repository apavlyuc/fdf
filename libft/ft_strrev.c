/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 01:52:30 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/12/04 05:22:54 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strrev(char *s)
{
	char	*rev;
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	rev = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (i != -1)
	{
		*rev++ = *(s + i);
		i--;
	}
	*rev = '\0';
	return (rev - ft_strlen(s));
}
