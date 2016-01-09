##
## Makefile for Makefile awesome in /home/troncy_l/prog/Rush1/step_1
## 
## Made by 
## Login   <troncy_l@epitech.net>
## 
## Started on  Fri Jan  8 20:22:35 2016 
## Last update Sat Jan  9 06:02:41 2016 
##

SRCS	=	src/main.c \
		src/my_write.c

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-I./include -W -Wall -Wextra -ansi -pedantic -g

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
