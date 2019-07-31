/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:04:14 by ljalikak          #+#    #+#             */
/*   Updated: 2019/03/05 11:33:46 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!to_find[0])
		return ((char *)str);
	while (str[i])
	{
		while (str[i + j] == to_find[j])
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
