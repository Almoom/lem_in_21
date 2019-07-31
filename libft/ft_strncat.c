/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:39:53 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/05 20:52:36 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *app, size_t n)
{
	char *s;

	s = dest;
	while (*s)
		s++;
	while (*app && n > 0)
	{
		*s++ = *app++;
		n--;
	}
	*s = '\0';
	return (dest);
}
