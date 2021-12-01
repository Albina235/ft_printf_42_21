# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evalorie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 11:40:19 by evalorie          #+#    #+#              #
#    Updated: 2021/12/01 11:46:54 by evalorie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c	ft_printf_utils_transform.c

HEADER	=	ft_printf.h

OBJ		=	${SRCS:%.c=%.o}

CCF		=	gcc -Wall -Werror -Wextra

.PHONY	:	all claen fclean re

all		:	${NAME}

${NAME}	:	${OBJ} ${HEADER}
	ar rcs ${NAME} $?

%.o		:	%.c ${HEADER}
	${CCF} -c $< -o $@

clean	:
	@rm -f ${OBJ}

fclean	:	claen
	@rm -f ${NAME}

re		:	fclean all
