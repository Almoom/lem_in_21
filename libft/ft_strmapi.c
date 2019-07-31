/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:10:51 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/09 10:20:10 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*t;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(t = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		t[i] = f(i, s[i]);
		i++;
	}
	return (t);
}
