/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:41:43 by ljalikak          #+#    #+#             */
/*   Updated: 2019/05/07 17:41:45 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev_free(char *s, int flag)
{
	char	*t;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	k = 0;
	i = ft_strlen(s);
	t = ft_strnew(i);
	while (k < (int)ft_strlen(s))
	{
		t[k] = s[i - 1];
		k++;
		i--;
	}
	flag == 1 ? free(s) : 0;
	return (t);
}
