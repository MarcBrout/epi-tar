##
## Makefile for Makefile awesome in /home/troncy_l/prog/Rush1/step_1
## 
## Made by 
## Login   <troncy_l@epitech.net>
## 
## Started on  Fri Jan  8 20:22:35 2016 
## Last update Sun Jan 10 00:14:27 2016 
##

SRCS	=	src/main.c			\
		src/ope.c			\
		src/options.c			\

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-W -Wall -Wextra -Werror -ansi -pedantic -g

CFLAGS	+=	-Iinclude

NAME	=	my_unarchive

${NAME}:	${OBJS}
		gcc -o ${NAME} ${OBJS} ${CFLAGS}

all:		${NAME}

clean:
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all
