/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:48:04 by ilarbi            #+#    #+#             */
/*   Updated: 2017/08/02 21:21:13 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include "ft_printf.h"

char	*ft_convert(const char **format, int *written, va_list ap)
{
	t_format	*f;
	int			size;
	char		*number;

	number = NULL;
	size = 0;
	f = ft_parse(format, written);
	if (!f)//plus tard, enlever pad print er retour null se fera naturellement
		return(NULL);
	if (*(f->type) == '%')
		number = ft_percent(&f, &size);
	else if (*(f->type) == 'p')
		number = ft_redirect_p(&f, va_arg(ap, void*), &size);
	else if (ft_issigned(*(f->type)))
		number = ft_cast_signed((void *)va_arg(ap, intmax_t), f, &size);
	else if (ft_isunsigned(*(f->type)))
		number = ft_cast_unsigned((void*)va_arg(ap, uintmax_t), f, &size);
	else if (ft_tolower(*(f->type)) == 'c')
		number = ft_chartostr((int)va_arg(ap, intmax_t), f, &size);
	else if (ft_tolower(*(f->type)) == 's')
		number = ft_wstrtostr((char *)va_arg(ap, void *), f, &size);
	else
		number = ft_invalid_type(f->type, &size);
	ft_padandprint(&number, &f, written, &size);
	ft_fdel(&f);
	//((number) ? ft_strdel(&number) : 0);
	return (number);
}
/*
int		main()
{
	int			written = 0;
	//setlocale(LC_ALL, "");
	//long long	D = -2147;
	char c = 'A';
//	wchar_t c = 945;
	const char	*format = "c";
	//printf("%-1%");
	//printf("printf %#10lx\n", (unsigned long)&c );
	//printf("printf %20p\n", &c );
	ft_convert(&format, &written, c);
//	printf("printf : [%p]", &c);
	//ft_putnbr(printf("%D\n", 2147));
	return (0);
}
*/
