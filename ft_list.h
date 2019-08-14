/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:14:21 by ljalikak          #+#    #+#             */
/*   Updated: 2019/06/19 14:14:22 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# define TRUE 1
# define FALSE 0
# define END -1000
# define START 1000

typedef struct		s_val
{
	struct s_val	*next;
	char			*line;
	char			*name;
	char			*x_y;
	char			*name1;
	char			*name2;
	int				isnum;
	int				isstart;
	int				isend;
	int				isxy;
	int				isedge;
}					t_val;

typedef struct		s_mod
{
	struct s_mod		*next;
	char			*line;
	int				weight;
	char			*name1;
	char			*name2;
	int				c1;
	int				c2;
	int				loc;
	int				ants;
	char			*start;
	char			*end;
}					t_mod;

typedef struct		s_const
{
	int				ants;
	char			*start;
	char			*end;
}					t_const;

typedef struct		s_way
{
	struct s_way	*next;
	char			*name;
	int				len;
	int				ants;
	int				ants_way;
	int				num_ant;
	char			*start;
	char			*end;
}					t_way;

// typedef struct		s_ant
// {
// 	struct s_ant	*next;
// 	char			*name;
// 	int				atstart;
// 	int				in;
// 	int				out;
// 	char			*end;
// }					t_ant;
void				del_list_valid(t_val **del);
void				killer(t_mod **head, int count, char **hub, t_const *list);
void				del_hub(char **hub);
#endif
