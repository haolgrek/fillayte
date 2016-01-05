/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:34:56 by tandrieu          #+#    #+#             */
/*   Updated: 2016/01/04 17:13:28 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/*t_list	*ft_letter_assignation(t_list *list)
{
	int		letter;
	int		i;
	int		j;

	letter = 65;
	while (list)
	{
		j = 0;
		while (i < 4)
		{
			i = 0;
			while (i < 4)
			{
				if (list->array[i][j] == '#')
					list->array[i][j] = letter;
				i++;
			}
			j++;
		}
		letter++;
		list = list->next;
	}
	return (list);
}
*/
/*char	**fill_tab_w_point(char **ftab, int sqrt_calc)
{
	int		i;
	int		j;

	i = 0;
	printf("%d\n", sqrt_calc);
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			ftab[i][j] = '.';
		//	printf("%c", ftab[i][j]);
			j++;
		}
		i++;
	}
	return (ftab);
}
*/
char	**create_final_tab(char *tab)
{
	printf("%s\n", "hello");
	return(NULL);
}
