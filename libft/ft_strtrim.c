/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:19:08 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/09 13:58:28 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t		i;
	size_t		e;
	const char	*t;

	i = 0;
	e = 0;
	if (!s)
		return (NULL);
	while ((*s == '\n' || *s == '\t' || *s == ' ') && *s != '\0')
		s++;
	t = s;
	if (!(*s))
		return (ft_strnew(0));
	i = ft_strlen(s);
	t = s + i - 1;
	while (*t == '\n' || *t == '\t' || *t == ' ')
	{
		t--;
		e++;
	}
	return (ft_strsub(s, 0, i - e));
}
