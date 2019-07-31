/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:37:06 by ljalikak          #+#    #+#             */
/*   Updated: 2019/05/07 17:37:09 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(const char *s1, const char *s2, int f1, int f2)
{
	char	*t;
	size_t	i;
	size_t	l1;
	size_t	l2;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if ((l1 + l2 < l1) || (l1 + l2 < l2) || !(t = ft_strnew(l1 + l2)))
		return (NULL);
	while (++i < l1)
		t[i] = s1[i];
	while (i < l1 + l2)
	{
		t[i] = s2[i - l1];
		i++;
	}
	f1 == 1 ? free((void *)s1) : 0;
	f2 == 1 ? free((void *)s2) : 0;
	return (t);
}
