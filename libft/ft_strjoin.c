/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlyuc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:35:48 by apavlyuc          #+#    #+#             */
/*   Updated: 2017/11/30 14:51:48 by apavlyuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	string = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
											ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	ft_strcpy(string, s1);
	ft_strcpy(string + ft_strlen(s1), s2);
	return (string);
}
