/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 06:07:51 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/12/04 05:07:18 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		get_int_size(long int n)
{
	int			size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size = 1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static int		get_del(int n)
{
	int			del;

	del = 1000000000;
	while ((n / del) == 0)
	{
		del /= 10;
		if (n == 0)
			return (1);
	}
	return (del);
}

char			*ft_itoa(int n)
{
	char		*string;
	long int	nn;
	int			i;
	int			del;

	nn = n;
	string = (char *)ft_memalloc(sizeof(char) * (get_int_size(nn) + 1));
	i = -1;
	if (!string)
		return (NULL);
	if (nn < 0)
	{
		*(string + ++i) = '-';
		nn = -nn;
	}
	del = get_del(n);
	while (del != 0)
	{
		*(string + ++i) = (nn / del) + '0';
		nn -= del * (nn / del);
		del /= 10;
	}
	*(string + ++i) = '\0';
	return (string);
}
