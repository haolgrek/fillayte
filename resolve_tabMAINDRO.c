/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:24:33 by fpasquer          #+#    #+#             */
/*   Updated: 2016/01/04 13:24:36 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "file.h"
#include "libft/libft.h"
#include "lst.h"
#include "file.h"
#include "resolve.h"

void	ft_print_tab(char **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	**ft_init_tabresult(int size)
{
	char			**retour;
	int				y;

	if ((retour = (char**)ft_memalloc(sizeof(char*) * size + 1)) != NULL)
	{
		y = 0;
		while (y < size)
		{
			if ((retour[y] = ft_memalloc(sizeof(char) * size + 1)) == NULL)
				return (ft_free_strplit(retour));
			ft_memset(retour[y++], EMPTY, size);
		}
	}
	return (retour);
}

int		init_sizesquare(t_bloc *pieces)
{
	int				nb_pieces;
	int				result;

	result = 1;
	while (pieces->next)
		pieces = pieces->next;
	nb_pieces = pieces->index + 1;
	while ((result * result) < nb_pieces * 4)
		result++;
	return (result);
}
