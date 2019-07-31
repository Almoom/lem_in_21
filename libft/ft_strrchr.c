/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:54:20 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/05 18:04:58 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	const char *t;

	t = NULL;
	while (*str)
	{
		if (*str == ch)
			t = str;
		str++;
	}
	if (*str == ch)
		t = str;
	return ((char *)t);
}
