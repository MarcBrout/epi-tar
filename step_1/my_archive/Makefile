##
## Makefile for Makefile awesome in /home/troncy_l/prog/Rush1/step_1
## 
## Made by 
## Login   <troncy_l@epitech.net>
## 
## Started on  Fri Jan  8 20:22:35 2016 
## Last update Sun Jan 10 06:44:14 2016 marc brout
##

SRCS	=	src/main.c \
		src/my_write.c \
		src/header.c \
		src/recurs.c \
		src/launch_my_archive.c

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-I./include -W -Wall -Wextra -Werror -ansi -pedantic -g

NAME	=	my_archive

.c.o:
	gcc -c $< -o $@ ${CFLAGS}

${NAME}:	${OBJS}
		gcc -o ${NAME} ${OBJS}

all:		${NAME}

clean:
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all
