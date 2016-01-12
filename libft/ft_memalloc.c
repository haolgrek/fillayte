/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:14:07 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/21 16:14:08 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = (void*)malloc(sizeof(void) * size);
	if (mem)
	{
		ft_bzero(mem, size + 1);
		return (mem);
	}
	return (NULL);
}
