/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 01:15:29 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/24 06:03:57 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *href;

	href = (char *)malloc(((int)size + 1) * sizeof(char));
	if (href == NULL)
		return (NULL);
	ft_memset(href, '\0', size + 1);
	return (href);
}
