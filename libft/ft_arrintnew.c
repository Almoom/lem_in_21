/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrintnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:18:51 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/29 11:18:55 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_arrintnew(int row, int col)
{
	int		i;
	int		**tab;

	i = 0;
	if (!(tab = (int**)ft_memalloc(sizeof(tab) * row)))
		return (0);
	while (i < row)
	{
		if (!(tab[i] = (int*)ft_memalloc(sizeof(*tab) * col)))
		{
			ft_arrintfree(tab, i - 1);
			return (0);
		}
		i++;
	}
	return (tab);
}
