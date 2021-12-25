/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:58:08 by gkelsie           #+#    #+#             */
/*   Updated: 2021/10/11 13:17:41 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>

size_t	ft_strlen(const char *s);
int		ft_putstr(char *str);
int		ft_putchar(char ch);
int		ft_char_proc(char ch, int count);
int		ft_hex_proc(unsigned int num, int ch, int count);
int		ft_int_proc(int num, int count);
int		ft_percent_proc(char ch, int count);
int		ft_ptr_proc(unsigned long num, int count);
int		ft_str_proc(char *str, int count);
int		ft_uint_proc(int num, int count);
int		ft_printf(const char *s, ...);
#endif