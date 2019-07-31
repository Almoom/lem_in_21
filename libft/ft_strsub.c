/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:00:45 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/09 11:24:39 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t n)
{
	char	*t;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(t = ft_strnew(n)))
		return (NULL);
	s = s + start;
	while (i < n)
	{
		t[i] = s[i];
		i++;
	}
	return (t);
}
