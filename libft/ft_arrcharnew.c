/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcharnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:26:04 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/29 11:26:06 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrcharnew(int row, int col)
{
	int		i;
	char	**str;

	i = 0;
	if (row + 1 < row || !(str = (char**)ft_memalloc(sizeof(str) * (row + 1))))
		return (0);
	while (i < row)
	{
		if (!(str[i] = ft_strnew(col)))
		{
			ft_arrcharfree(str);
			return (0);
		}
		i++;
	}
	return (str);
}
