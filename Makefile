#Compilation

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
INC = -I.

#VALUES

NAME	= pipex

#SOURCES

FILES	=	ft_exit.c		\
			ft_parsing.c		\
			ft_pipex.c		\
			ft_strlcpy.c		\
			ft_init.c		\
			ft_path.c		\
			ft_split.c		\
			main.c		\

OBJS	= ${FILES:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJS)
		@cc $(OBJS) -I./includes -I./usr/include -Wall -Wextra -Werror -o $(NAME)

all:	$(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
				rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

