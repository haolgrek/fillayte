/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:24:07 by rluder            #+#    #+#             */
/*   Updated: 2016/01/05 15:33:19 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		can_be_put(char **tab, t_list *list, int *value)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while ((i < 4) && (value[0] + i) < value[2] && count < 4)
	{
		j = 0;
		while ((j < 4) && (value[1] + j) < value[2] && count < 4)
		{
			if (tab[value[0] + i][value[1] + j] != '.' && list->array[i][j] != '.')
				return (0);
			if (tab[value[0] + i][value[1] + j] == '.' && list->array[i][j] != '.')
				count++;
			j++;
		}
		i++;
	}
	return ((count == 4) ? 1 : 0);
}

char	**add_tetri(char **tab, t_list *list, int letter, int *value)
{
	int		i;
	int 	j;

	i = 0;
	while ((i < 4) && (value[0] + i) < value[2])
	{
		j = 0;
		while ((j < 4) && (value[1] + j) < value[2])
		{
			if (tab[value[0] + i][value[1] + j] == '.' && list->array[i][j] != '.')
				tab[value[0] + i][value[1] + j] = letter;
			j++;
		}
		i++;
	}
	return (tab);
}

char	**suppr_tetri(char **tab, char letter, int *value)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < value[2])
	{
		j = 0;
		while (j < value[2])
		{
			if (tab[i][j] == letter)
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}

char	**backtracking(char **tab, t_list *list, int sqrt)
{
	char	letter;
	int		value[3];
	value[0] = 0;
	value[1] = 0;
	value[2] = sqrt;

	while (value[0] < value[2])
	{
		if (can_be_put(tab, list, value))
		{
			letter = 'A' + list->index;
			tab = add_tetri(tab, list, letter, value);
			if (backtracking(tab, list->next, sqrt))
				return (tab);
			tab = suppr_tetri(tab, letter, value);
		}
		value[1]++;
		if (value[1] > value[2])
		{
			value[1] = 0;
			value[0]++;
		}
	}
	return (NULL);
}

