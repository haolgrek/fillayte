/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:18:06 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/21 16:18:08 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	char	*tmp;
	size_t	size;

	size = (n < ft_strlen(s1) + 1) ? n : ft_strlen(s1);
	if ((s2 = ft_memalloc(size + 1)) == NULL)
		return (NULL);
	tmp = s2;
	while (*s1 != '\0' && n > 0)
	{
		*s2++ = *s1++;
		n--;
	}
	*s2 = '\0';
	return (tmp);
}
