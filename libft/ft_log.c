/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 12:08:03 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/29 12:08:05 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_log(int base, int rez)
{
	int i;

	i = 1;
	if (rez >= base && base > 1)
	{
		if (rez / base == 1)
			return (1);
		else
			return (i + ft_log(base, rez / base));
	}
	return (0);
}
