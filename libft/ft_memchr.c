/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:20:59 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/07 20:33:52 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dest, int c, size_t n)
{
	unsigned char *t;

	t = (unsigned char *)dest;
	while (n > 0)
	{
		if (*t == (unsigned char)c)
			return (t);
		t++;
		n--;
	}
	return (NULL);
}
