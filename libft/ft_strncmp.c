/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:59:41 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/30 18:54:06 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = -1;
	if (!n)
		return (0);
	while (*(s1 + ++i) != '\0')
	{
		if (n - i - 1 <= 0)
			break ;
		if (*(s1 + i) != *(s2 + i))
			return (*(unsigned char *)(s1 + i) -
					*(unsigned char *)(s2 + i));
	}
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}
