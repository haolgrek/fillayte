/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:24:07 by rluder            #+#    #+#             */
/*   Updated: 2016/01/05 13:44:51 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		can_be_put(char **tab, int sqrt, t_list list)

char	**add_tetri(char **tab, t_list list)

char	**suppr_tetri(char **tab, char letter)

char	**backtracking(char **tab, t_list list, int sqrt)
{
	char	letter;
	int		i;
	int		j;

	while (i < sqrt)
	{
		if (can_be_put(tab, sqrt, list))
		{
			letter = 'A' + list->index; //ajouter int dans struct
			tab = add_tetri(tab, list);
			if (backtracking(tab, list->next))
				return (tab);
			tab = suppr_tetri(tab, letter);
		}
		j++;
		if (j > sqrt)
		{
			j = 0;
			i++;
		}
	}
	return (NULL);
}

