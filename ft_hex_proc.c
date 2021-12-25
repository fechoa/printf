/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:45:34 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/11 13:16:27 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putnbr_base(int n, char *str, int *count)
{
	unsigned int	num;

	num = (unsigned int)n;
	if (num >= 0 && num <= 15)
	{
		(*count)++;
		ft_putchar(str[num]);
	}
	else
	{
		ft_putnbr_base(num / 16, str, count);
		ft_putchar(str[num % 16]);
		(*count)++;
	}
}

int	ft_hex_proc(unsigned int num, int ch, int count)
{	
	if (ch == 'x')
		ft_putnbr_base(num, "0123456789abcdef", &count);
	if (ch == 'X')
		ft_putnbr_base(num, "0123456789ABCDEF", &count);
	return (count);
}
