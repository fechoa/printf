/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:40:00 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/11 12:45:29 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_head_program(int ch, va_list ap, int count)
{
	if (ch == 'c')
		count += ft_char_proc(va_arg(ap, int), 0);
	else if (ch == '%')
		count += ft_percent_proc(va_arg(ap, int), 0);
	else if (ch == 's')
		count += ft_str_proc(va_arg(ap, char *), 0);
	else if (ch == 'd' || ch == 'i')
		count += ft_int_proc(va_arg(ap, int), 0);
	else if (ch == 'u')
		count += ft_uint_proc(va_arg(ap, unsigned int), 0);
	else if (ch == 'x' || ch == 'X')
		count += ft_hex_proc(va_arg(ap, unsigned int), ch, 0);
	else if (ch == 'p')
		count += ft_ptr_proc(va_arg(ap, unsigned long), 0);
	return (count);
}

static	bool	ft_is_type_pars(char ch)
{
	return (ch == 'd' || ch == 'i'
		|| ch == 'u' || ch == 'x'
		|| ch == 'X' || ch == 'p'
		|| ch == 'c' || ch == 's');
}

static int	ft_parser(const char *s, va_list ap)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (1)
	{
		if (s[i] == '\0')
			break ;
		if (s[i] != '%')
			count += ft_putchar(s[i]);
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			if (ft_is_type_pars(s[i]))
				count += ft_head_program(s[i], ap, 0);
			else
				count += ft_putchar(s[i]);
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		result;

	result = 0;
	va_start(ap, s);
	result += ft_parser(s, ap);
	va_end(ap);
	return (result);
}
