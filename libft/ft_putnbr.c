/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 07:06:17 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/12/03 20:47:35 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_del(int nn)
{
	int			del;

	del = 1000000000;
	while ((nn / del) == 0)
		del /= 10;
	return (del);
}

void			ft_putnbr(int n)
{
	int			del;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n == 0)
	{
		ft_putstr("0");
		return ;
	}
	del = get_del(n);
	while (del != 0)
	{
		ft_putchar((n / del) + '0');
		n -= del * (n / del);
		del /= 10;
	}
}
