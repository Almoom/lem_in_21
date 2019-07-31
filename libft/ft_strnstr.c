/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:14:07 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/07 18:14:09 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!to_find[0])
		return ((char *)str);
	while (str[i] && i < n)
	{
		while (str[i + j] == to_find[j] && i + j < n)
		{
			j++;
			if (!to_find[j])
				return ((char *)str + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
