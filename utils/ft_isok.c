/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:08:57 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/13 13:53:45 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../ft_printf.h"

int		ft_isok(char c)
{
	return ((ft_istype(c) || c == '%') ? 1 : 0);
}
