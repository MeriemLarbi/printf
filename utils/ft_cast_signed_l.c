/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_signed_l.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:41:48 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/26 16:02:23 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

char	*ft_cast_signed_l(intmax_t result)
{
	long	l;
	char	*number;

	if ((long)result < LONG_MIN || (long)result > LONG_MAX)
		return (NULL);
	l = (long)result;
	number = ft_itoa_max_base(l, 10);
	return (number);
}
/*
int		main()
{
	//intmax_t l = -9223372036854775808;
	printf("%s\n",ft_cast_signed_l(-1247)); 
	return (0);
}*/
