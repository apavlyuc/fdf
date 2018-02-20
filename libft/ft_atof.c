/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:38:35 by apavlyuc          #+#    #+#             */
/*   Updated: 2018/02/19 19:12:50 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float				ft_atof(const char *str)
{
	float			f;
	int				p;

	f = ft_atoi(str);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	str = (*str == '-' || *str == '+') ? (str + 1) : (str);
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
	{
		str++;
		p = 10;
		while (ft_isdigit(*str))
		{
			f = f + ((f < 0) ? (-1) : (1)) * ((float)(*str - '0') / (float)p);
			p *= 10;
			str++;
		}
	}
	return (f);
}
