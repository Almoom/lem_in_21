/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 12:06:28 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/29 12:06:30 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pwr(int nb, int pwr)
{
	if (pwr < 0 || nb != (nb * 10) / 10)
		return (0);
	if (pwr == 0 || nb == 1)
		return (1);
	if (pwr == 1)
		return (nb);
	else if (pwr % 2 == 1)
		return (nb * ft_pwr(nb, pwr - 1));
	else
		return (ft_pwr(nb * nb, pwr >> 1));
}
