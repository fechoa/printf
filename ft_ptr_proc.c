/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:44:58 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/11 13:17:24 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putnbr_base_ptr(unsigned long num, char *str, int *count)
{
	if (num >= 0 && num <= 15)
	{
		(*count)++;
		ft_putchar(str[num]);
	}
	else
	{
		ft_putnbr_base_ptr(num / 16, str, count);
		ft_putchar(str[num % 16]);
		(*count)++;
	}
}

int	ft_ptr_proc(unsigned long num, int count)
{	
	ft_putstr("0x");
	count += 2;
	ft_putnbr_base_ptr(num, "0123456789abcdef", &count);
	return (count);
}
