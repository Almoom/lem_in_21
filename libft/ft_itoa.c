/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:43:15 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/10 17:18:02 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isize(long n)
{
	int i;

	i = 0;
	if (n == 0 || n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	long	t;

	t = n;
	i = ft_isize(t);
	if (!(s = ft_strnew(i)))
		return (NULL);
	if (t < 0)
	{
		s[0] = '-';
		t *= -1;
	}
	while (i > 0)
	{
		if (s[i - 1] != '-')
			s[i - 1] = (t % 10) + '0';
		t /= 10;
		i--;
	}
	return (s);
}
