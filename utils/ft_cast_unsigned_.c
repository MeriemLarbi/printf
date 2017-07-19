/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_unsigned_.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:47:11 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/30 22:01:22 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_cast_unsigned_(uintmax_t result, int base)
{
	unsigned	u;
	char		*number;

	u = (unsigned)result;
	//if (u > UINT_MAX)
	//	return (NULL);
	number = ft_uitoa_max_base(u, base);
	return (number);
}
