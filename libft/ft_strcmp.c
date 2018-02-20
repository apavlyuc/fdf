/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:40:57 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/30 16:49:00 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = -1;
	while (*(s1 + ++i) != '\0' && *(s2 + i) != '\0')
		if (*(s1 + i) != *(s2 + i))
			return (*(unsigned char *)(s1 + i) -
					*(unsigned char *)(s2 + i));
	return (*(unsigned char *)(s1 + i) -
		*(unsigned char *)(s2 + i));
}
