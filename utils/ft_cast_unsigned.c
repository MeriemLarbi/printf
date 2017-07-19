/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:05:08 by ilarbi            #+#    #+#             */
/*   Updated: 2017/07/19 19:28:49 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_cast_unsigned(void *result, t_format *f, int *size)
{
	char	*number;

	if (!f || !(f->type) || !size)
		return (NULL);
	if ((f->len && f->len->l) || *(f->type) == 'O' || *(f->type) == 'U')
		number = ft_cast_unsigned_l((unsigned long)result, ft_assign_base(f));
	else if (!(f->len))
		number = ft_cast_unsigned_((unsigned)result, ft_assign_base(f));
	else if (f->len->hh)
		number = ft_cast_unsigned_hh((unsigned)result, ft_assign_base(f));
	else if (f->len->h)
		number = ft_cast_unsigned_h((unsigned)result, ft_assign_base(f));
	else if (f->len->ll)
		number = ft_cast_unsigned_ll((unsigned long long)result,
				ft_assign_base(f));
	else if (f->len->j)
		number = ft_cast_unsigned_j((uintmax_t)result, ft_assign_base(f));
	else if (f->len->z)
		number = ft_cast_unsigned_z((unsigned long long)result,
				ft_assign_base(f));
	if (!result && f->width
		&& (!(f->width->max) || (f->width->precision && f->width->max == -1)))
		*size = ((ft_tolower(*(f->type)) == 'o' && f->flags && f->flags->hash)
				? (1) : (0));
	else
		*size = ft_strlen(number);
	return ((*(f->type) == 'x') ? ft_strminimalize(&number) : number);
}
