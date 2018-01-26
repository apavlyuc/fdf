/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partscount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 21:55:40 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/12/03 23:08:27 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_partscount(char *str, char *del)
{
	int count;
	int i;

	if (!str || !del)
		return (0);
	count = 0;
	i = 0;
	while (*str != '\0')
	{
		if (*str == *(del + i))
			i++;
		else
		{
			str = str - i;
			i = 0;
		}
		if (i == (int)ft_strlen(del))
		{
			count++;
			i = 0;
		}
		str++;
	}
	return (count);
}
