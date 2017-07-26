/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padandprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:22:07 by ilarbi            #+#    #+#             */
/*   Updated: 2017/07/26 21:42:51 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		ft_fldsize(t_format *f, int size)
{
	int		fldsize;
	
	if (!f)
		return (-1);
	fldsize = size;
	if (f->width && f->width->max >= 0)
	{
		fldsize = ((f->width->max > size && ft_isnumeric(*(f->type))) ? f->width->max : size);
   		if (*(f->type) == 'o' && f->flags && f->flags->hash && f->width->min > size)
			((fldsize > size) ? fldsize : fldsize++);
	}
	return (fldsize);
}

void	ft_prepend(char c, int nbr, int *written)
{
	int		i;

	i = 0;
	if (c == 'x')
		write(1, "0x", (nbr = 2));
	else if (c == 'X')
		write(1, "0X", (nbr = 2));
	else if (ft_tolower(c) == 'o')
		write(1, "0", (nbr = 1));
	else
	{
		while (i++ < nbr)
			write(1, &c, 1);
	}
	*written += nbr;
}

int		ft_pad(char *str, t_format *f, int size, int fldsize)
{
	int		pad;
	
	if (!f)
		return (0);
	pad = 0;
	if (f->width  && f->width->min > fldsize)
	{
		pad = f->width->min - fldsize;
		if (size > f->width->max) // fldsize = taille
		{
			if (ft_tolower(*(f->type)) == 'o' && f->flags 
				&& f->flags->hash)
			  pad -= 1;
		}	
		if ((ft_tolower(*(f->type)) == 'x' && f->flags && f->flags->hash && *str != '0') || (*(f->type) == 'p')) 
			pad -= 2;
		if (ft_isnumeric(*(f->type)) && (*str == '-' 
			|| (f->flags && (f->flags->space || f->flags->plus))))
			pad -= 1;
	}
	return ((pad > 0) ? pad : 0);
}

void	ft_printsign(char **str, t_format **f, int *written)
{
	char sign;

	sign = '\0';

	if (!*str || !*f || !written || !((*f)->type))
		return ;
	if (ft_issigned(*((*f)->type)) && (*(*str) == '-' || ((*f)->flags 
				&& ((*f)->flags->plus || (*f)->flags->space))))
	{
		((*(*str) == '-') ? (sign = '-') : 0);
		if ((*f)->flags && !sign 
			&& ((*f)->flags->plus || (*f)->flags->space))
			(((*f)->flags->plus) ? (sign = '+') : (sign = ' '));
		ft_prepend(sign, 1, written);
	}
}

void	ft_padandprint(char **str, t_format **f, int *written, int *sz)
{
	int		fldsize;
	int		pmin;
	int		padded;
	char	pad[2];

	if (!*f || !written)
		return ;
	fldsize = ft_fldsize(*f, *sz);
	pmin = ft_pad(*str, *f, *sz, fldsize);
	padded = 0;
	pad[0] = 'r';
	pad[1] = ' ';
	//printf("pmin %d sz %d str %s\n", pmin, *sz, *str);
	if ((*f)->width && (*f)->width->min > fldsize)
	{
		if ((*f)->flags && ((*f)->flags->zero || (*f)->flags->minus))
			(((*f)->flags->minus) ? (pad[0] = 'l') 
			 : (pad[1] = '0'));
		if (pad[0] == 'r' && pad[1] == ' ' && !padded && (padded = 1))
			ft_prepend(pad[1], pmin, written);
	}
	ft_printsign(str, f, written);
	if (*((*f)->type) == 'p')
		ft_prepend('x', 2, written);
	if (pad[0] == 'r' && pad[1] == '0' && ft_tolower(*((*f)->type)) != 'x' && !padded && (padded = 1))
		ft_prepend(pad[1], pmin, written);
	if ((*f)->flags && (*f)->flags->hash && *(*str) != '0')
		ft_prepend(*((*f)->type), 1, written);
	if (ft_isnumeric(*((*f)->type)) && (fldsize > *sz || ((*f)->flags && (*f)->flags->zero && pmin && !padded && (padded = 1))))	
		((fldsize > *sz) ? (ft_prepend('0', fldsize - *sz, written)) : (ft_prepend('0', pmin, written)));
	((ft_issigned(*((*f)->type)) && *(*str) == '-' && *sz) ? write(1, *str + 1, *sz) : write(1, *str, *sz));
	*written += *sz;
	if ((*f)->width && (*f)->width->min > fldsize && pad[0] == 'l' && !padded && (padded = 1))
		ft_prepend(pad[1], pmin, written);
}
/*
int		main()
{
	//int written = 0;
	//char str = ' ';
	//ft_prepend(str, 5, &written);
	//printf("%d\n", written);
	//printf("%-4d\n", size(str));
	t_format *f = ft_memalloc(sizeof(t_format));
	f->width = ft_memalloc(sizeof(t_width));
	f->flags = ft_memalloc(sizeof(t_flags));
	f->width->min = 14;
	f->width->max = 10;
	int size = 11;
	f->type = "o";
	f->flags->hash = 1;
	char *str = "-65";
	printf("fldsize : %d", ft_fldsize(f, size));
	printf("pad : %d", ft_pad(str, f, size, ft_fldsize(f, size)));
	return (0);
}
*/
