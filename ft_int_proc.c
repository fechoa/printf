/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:46:37 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/11 12:34:06 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putnbr(int n, int *count)
{
	long int	num;

	num = (long int)n;
	if (num < 0)
	{
		write(1, "-", 1);
		(*count)++;
		num = num * -1;
	}
	if (num >= 0 && num <= 9)
	{
		(*count)++;
		ft_putchar((char)(num + 48));
	}
	else
	{
		ft_putnbr(num / 10, count);
		ft_putchar((char)(num % 10 + 48));
		(*count)++;
	}
}

int	ft_int_proc(int num, int count)
{	
	ft_putnbr(num, &count);
	return (count);
}
