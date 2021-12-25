# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 09:36:16 by gkelsie           #+#    #+#              #
#    Updated: 2021/10/11 12:44:59 by gkelsie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c		ft_char_proc.c		ft_hex_proc.c\
			ft_int_proc.c	ft_percent_proc.c	ft_ptr_proc.c\
			ft_putchar.c	ft_putstr.c			ft_str_proc.c\
			ft_strlen.c		ft_uint_proc.c\

OBJS	=	${SRCS:.c=.o}

OBJS_D	=	$(patsubst %.c,%.d,$(SRCS) $(SRCS_B))

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

FLAGS_O	=	-O2

all		:	$(NAME)

$(NAME)	: ${OBJS}
	ar rcs $(NAME) $?

%.o		:	%.c
	gcc $(FLAGS) $(FLAGS_O) -c $< -o $@ -MD

include $(wildcard $(OBJS_D))

clean	:
	rm -f $(OBJS) $(OBJS_B) $(OBJS_D)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus