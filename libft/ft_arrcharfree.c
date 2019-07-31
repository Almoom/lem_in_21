/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcharfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:31:20 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/29 11:31:22 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrcharfree(char **str)
{
	int		n;

	n = 0;
	if (!str)
		return ;
	while (str[n])
	{
		free(str[n]);
		n++;
	}
	free(str);
}