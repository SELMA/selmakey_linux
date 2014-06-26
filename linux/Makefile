##
## Makefile for selmakey in /home/alexmog/projets/SELMA/selmakey/linux
## 
## Made by Moghrabi Alexandre
## Login   <alexmog@epitech.net>
## 
## Started on  Thu Jun 26 20:25:41 2014 Moghrabi Alexandre
## Last update Thu Jun 26 21:58:42 2014 Moghrabi Alexandre
##

BINDIR= bin/

SRCDIR= src/

INCDIR= include/

NAME=	$(BINDIR)selmakey

SRC=	$(SRCDIR)main.c		\
	$(SRCDIR)listen.c	\
	$(SRCDIR)init.c

OBJ=	$(SRC:.c=.o)

RM=	rm -f

CC=	gcc

CFLAGS=	-W -Wall -Werror -I $(INCDIR)

LFLAGS=	

all: $(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		clean fclean all re
