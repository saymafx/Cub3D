# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 01:27:28 by ma1iik            #+#    #+#              #
#    Updated: 2023/03/18 09:47:07 by misrailo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d
HEADERS			=	cub3d.h
CC				= 	gcc
RM				= 	rm -rf
CFLAGS 			=  -Wall -Wextra -Werror -Wno-unused-variable -g -fsanitize=address
LIB_NAME		=	cub3d.a

SRCS	=	srcs/main.c \
			srcs/utils.c \
			srcs/utils1.c \
			srcs/drawing.c \
			srcs/drawing1.c \
			srcs/drawing2.c \
			srcs/drawing3.c \
			srcs/move1.c \
			srcs/move2.c \
			srcs/move3.c \
			srcs/parsing1.c \
			srcs/parsing2.c \
			srcs/parsing3.c \
			srcs/parsing4.c \
			srcs/parsing5.c \
			srcs/parsing6.c \
			srcs/parsing7.c \
			srcs/parsing8.c \

OBJS	= ${SRCS:.c=.o}

UNAME_S				= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LIBS 			= -L ./libft -lft -lmlx -lXext -lX11
endif
ifeq ($(UNAME_S),Darwin)
	LIBS 			= -L ./libft -lft -lmlx -framework OpenGL -framework AppKit -lz
endif

$(NAME):	${OBJS}
			make -C libft/
			${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME} -lm

all:	${NAME}

%.o: %.c	$(HEADERS)
			@${CC} -c ${CFLAGS} -o $@ $< 

clean:
		make -C libft/ clean
		${RM} ${OBJS}

fclean: clean
		make -C libft/ fclean
		${RM} ${NAME}

re:		fclean clean all

.PHONY:	all clean fclean re