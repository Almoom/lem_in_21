/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:27:49 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/05 13:30:32 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	rez;

	i = 0;
	sign = 1;
	rez = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] >= '0'
	&& str[i + 1] <= '9')
		sign = -1 * (str[i++] - 44);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (rez > 922337203685477580)
			return ((1 + sign) / -2);
		if (rez == 922337203685477580 && str[i] - 48 > 8 + (1 + sign) / -2)
			return ((1 + sign) / -2);
		rez = rez * 10 + (str[i++] - '0');
	}
	return ((int)rez * sign);
}
