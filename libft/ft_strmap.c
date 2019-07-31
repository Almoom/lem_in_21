/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:36:45 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/09 10:20:34 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*t;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(t = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i] != '\0')
	{
		t[i] = f(s[i]);
		i++;
	}
	return (t);
}
