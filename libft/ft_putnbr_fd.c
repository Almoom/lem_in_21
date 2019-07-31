/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:41:30 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/10 19:30:26 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	t;

	t = n;
	if (fd < 0)
		return ;
	if (t < 0)
	{
		ft_putchar_fd('-', fd);
		t = -t;
	}
	if (t > 9)
	{
		ft_putnbr_fd(t / 10, fd);
		ft_putnbr_fd(t % 10, fd);
	}
	else
		ft_putchar_fd(t + '0', fd);
}
