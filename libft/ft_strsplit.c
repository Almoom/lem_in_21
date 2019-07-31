/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:18:39 by ljalikak          #+#    #+#             */
/*   Updated: 2019/04/14 22:06:46 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_fnext(const char *str, char c, int flag)
{
	if (flag)
		while (*str && *str == c)
			str++;
	else
		while (*str && *str != c)
			str++;
	return (str);
}

static size_t		ft_count(const char *str, char c)
{
	size_t i;

	i = 0;
	while (*str)
	{
		str = ft_fnext(str, c, 1);
		if (*str)
		{
			i++;
			str = ft_fnext(str, c, 0);
		}
	}
	return (i);
}

static char			**ft_del(char **rez, int len)
{
	int i;

	i = 0;
	while (i < len)
		free(rez[i++]);
	free(rez);
	return (NULL);
}

char				**ft_strsplit(char const *str, char c)
{
	char		**rez;
	int			i;
	const char	*next;

	if (str == NULL)
		return (NULL);
	if ((ft_count(str, c) + 1 < ft_count(str, c)) ||
	!(rez = (char**)malloc(sizeof(char*) * (ft_count(str, c) + 1))))
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		str = ft_fnext(str, c, 1);
		if (*str)
		{
			next = ft_fnext(str, c, 0);
			rez[i] = ft_strsub(str, 0, next - str);
			if (rez[i] == NULL)
				return (ft_del(rez, i));
			i++;
			str = next;
		}
	}
	rez[i] = 0;
	return (rez);
}
