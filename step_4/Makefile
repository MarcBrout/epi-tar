##
## Makefile for MakeFile Tar in /home/troncy_l/prog/Rush1/step_3
## 
## Made by 
## Login   <troncy_l@epitech.net>
## 
## Started on  Sun Jan 10 01:29:57 2016 
## Last update Sun Jan 10 12:05:07 2016 marc brout
##

SRCS	=	src/main.c \
		src/header.c \
		src/launch_my_archive.c \
		src/my_write.c \
		src/ope.c \
		src/my_start.c \
		src/options.c \
		src/recurs.c \
		src/args.c \

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-I./include -W -Wall -Wextra -ansi -pedantic

NAME	=	my_tar

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
