/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 12:02:21 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/29 12:02:22 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sqrt(size_t n)
{
	size_t h;
	size_t l;

	if (n == 0 || n == 1)
		return (n);
	l = n >> 1;
	h = n;
	if (l * l < l)
		return (0);
	while (h - l > 1)
	{
		if (l * l > n)
		{
			h = l;
			l = l >> 1;
		}
		else if (l * l < n)
			l = (h + l) >> 1;
		if (l * l == n)
			return (l);
	}
	return (0);
}
