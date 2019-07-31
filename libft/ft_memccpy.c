/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:43:47 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/12 13:30:15 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *d;
	char *s;

	d = (char *)dest;
	s = (char *)src;
	while (n--)
	{
		*d = *s;
		d++;
		if ((unsigned char)*s == (unsigned char)c)
			return ((void *)d);
		s++;
	}
	return (NULL);
}
