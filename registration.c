/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:39:49 by tandrieu          #+#    #+#             */
/*   Updated: 2016/01/11 15:25:59 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

char	**ft_create_btab(char *file)
{
	char	**btab;
	int		x;
	int		value[3];

	value[0] = 0;
	value[1] = 0;
	value[2] = 0;
	btab = malloc(sizeof(char*) * 4);
	if (!btab)
	{
		return (0);
	}
	x = 0;
	while (x < 4)
	{
		btab[x++] = malloc(sizeof(char) * 5);
	}
	btab = ft_fill_btab(btab, file, value);
	return (btab);
}

char	**ft_fill_btab(char **btab, char *file, int *value)
{
	static int	i;

	if (i == 0)
		i = -1;
	if (i != 0)
		i++;
	while (value[2] < 4)
	{
		while (value[1] < 4)
		{
			while (value[0] < 5)
			{
				btab[value[1]][value[0]] = file[i];
				value[0]++;
				i++;
			}
			value[2]++;
			value[1]++;
			value[0] = 0;
		}
		value[1] = 0;
		value[0] = 0;
	}
	btab[3][4] = '\0';
	return (btab);
}

t_list	*create_list(char *file)
{
	t_list	*list;
	int		b;

	b = 0;
	list = NULL;
	while (b < (((int)ft_strlen(file) + 1) / 21))
	{
		list = ft_list_insert_back(list, file);
		b++;
	}
	return (list);
}

t_list	*ft_create_elem(char *file)
{
	t_list		*lst;
	static int	k;
	char		**btab;

	btab = ft_create_btab(file);
	lst = malloc(sizeof(t_list));
	if (lst)
	{
		lst->array = btab;
		lst->index = k;
		lst->next = NULL;
	}
	k = k + 1;
	return (lst);
}

t_list	*ft_list_insert_back(t_list *list, char *file)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = ft_create_elem(file);
	if (tmp)
	{
		if (list)
		{
			tmp2 = list;
			while (tmp2->next)
				tmp2 = tmp2->next;
			tmp2->next = tmp;
		}
		else
			list = tmp;
	}
	return (list);
}
