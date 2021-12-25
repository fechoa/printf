/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:47:08 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/11 12:42:02 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_str_proc(char *str, int count)
{
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (count + 6);
	}
	return (count + ft_putstr(str));
}
