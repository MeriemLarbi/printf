/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:04:19 by ilarbi            #+#    #+#             */
/*   Updated: 2017/07/20 13:44:09 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_istype(char c)
{
	return ((c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O'
				|| c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'c' ||
				c == 'C' || c == 's' || c == 'S' || c == 'p') ? 1 : 0);
}
