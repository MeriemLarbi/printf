/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:02:00 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/29 17:37:26 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*copy;

	i = ft_strlen(s1);
	j = 0;
	while (s1[i])
		i++;
	copy = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	ft_memset(copy, 0, (size_t)(i + 1));
	if (copy == NULL)
		return (copy);
	while (j < i)
	{
		copy[j] = s1[j];
		j++;
	}
	copy[i] = '\0';
	return (copy);
}
