/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:25:10 by fpasquer          #+#    #+#             */
/*   Updated: 2016/01/04 13:25:13 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "check.h"
#include "file.h"
#include "libft/libft.h"
#include "lst.h"
#include "file.h"
#include "resolve.h"

/*
** when tab is filled we return tab but until it is done we
** increase the size of sizesquare and redo
*/

void	ft_square_print(t_bloc *pieces)
{
	int		sizesquare;
	char	**tab;
	char	**tabresult;
	int		i;

	i = 0;
	tab = NULL;
	sizesquare = init_sizesquare(pieces);
	if ((tabresult = ft_init_tabresult(500)) == NULL)
		return ;
	while (tab == NULL)
	{
		tab = ft_fullfillsquare(tabresult, sizesquare, pieces);
		sizesquare++;
		i = 0;
	}
	ft_print_tab(tab, sizesquare - 1);
	ft_free_strplit(tabresult);
}

/*
** This function. While i < sizesqaure we check if the piece is valid.
** we add a new piece in the tabresult grid with the corresponding letter
** Then recursively call the function with the next element of the linked list
** pieces if the next element exists and if the function returns a tabresult
** else we remove the piece from the tabresult
** If we are at the end of line j>=sizesquare => go to next line
** If there is no pieces left we return tabresult. Else we continues
** var[0] = i
** var[1] = j
*/

char	**ft_fullfillsquare(char **tabresult, int sizesquare, t_bloc *pieces)
{
	char	letter;
	int		var[3];

	if (pieces == NULL)
		return (tabresult);
	var[0] = 0;
	var[1] = 0;
	while (var[0] < sizesquare)
	{
		if (ft_piecevalide(tabresult, var, sizesquare, pieces))
		{
			letter = 'A' + (pieces->index);
			tabresult = add_piece(tabresult, sizesquare, var, pieces);
			if (ft_fullfillsquare(tabresult, sizesquare, pieces->next))
				return (tabresult);
			tabresult = takeoff_piece(tabresult, sizesquare, letter);
		}
		var[1]++;
		if (var[1] >= sizesquare)
		{
			var[1] = 0;
			var[0]++;
		}
	}
	return (NULL);
}

/*
** in this function we check that the tabresult is empty to place the piece
** at the wanted location
** returns 1 if ok
** returns 0 if not ok
** v[0] = i
** v[1] = j
*/

int		ft_piecevalide(char **tabresult, int var[], int sizesquare,
		t_bloc *piece)
{
	int		index_i;
	int		index_j;
	int		count;

	count = 0;
	index_i = 0;
	index_j = 0;
	while ((index_i < 4) && (var[0] + index_i) < sizesquare && count < 4)
	{
		while ((index_j < 4) && (var[1] + index_j) < sizesquare && count < 4)
		{
			if (tabresult[var[0] + index_i][var[1] + index_j] != '.'
					&& piece->grid[index_i][index_j] != '.')
				return (0);
			if (tabresult[var[0] + index_i][var[1] + index_j] == '.'
					&& piece->grid[index_i][index_j] != '.')
				count++;
			index_j++;
		}
		index_j = 0;
		index_i++;
	}
	return ((count == 4) ? 1 : 0);
}

/*
** v[0] = i
** v[1] = j
*/

char	**add_piece(char **tabresult, int sizesquare, int var[], t_bloc *piece)
{
	int index_i;
	int index_j;

	index_i = 0;
	while ((index_i < 4) && (var[0] + index_i) < sizesquare)
	{
		index_j = 0;
		while ((index_j < 4) && (var[1] + index_j) < sizesquare)
		{
			if (tabresult[var[0] + index_i][var[1] + index_j] == '.'
					&& piece->grid[index_i][index_j] != '.')
				tabresult[var[0] + index_i][var[1] + index_j] =
					piece->grid[index_i][index_j];
			index_j++;
		}
		index_i++;
	}
	return (tabresult);
}

/*
** in this function we remove the piece from tabresult by replacing the letter
** with .
** v[0] = i
** v[1] = j
*/

char	**takeoff_piece(char **tabresult, int sizesquare, char letter)
{
	int index_i;
	int index_j;

	index_i = 0;
	index_j = 0;
	while (index_i < sizesquare)
	{
		index_j = 0;
		while (index_j < sizesquare)
		{
			if (tabresult[index_i][index_j] == letter)
				tabresult[index_i][index_j] = '.';
			index_j++;
		}
		index_i++;
	}
	return (tabresult);
}
