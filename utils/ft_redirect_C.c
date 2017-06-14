/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_C.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 19:55:13 by ilarbi            #+#    #+#             */
/*   Updated: 2017/06/14 20:01:32 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_redirect_C(t_format **f)
{
	if (!f || !*f)
		exit(-1);
	if (!*(f)->flags && !((*f)->flags = ft_memalloc(sizeof(t_flags))))
		exit(-1);
	(*f)->flags->l = 1;
	(*f)->type = "c";
}