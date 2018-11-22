# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aaudrain <aaudrain@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/12 16:06:15 by aaudrain     #+#   ##    ##    #+#        #
#    Updated: 2018/11/22 17:15:51 by igbraude    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iincludes -Ilibft
SOURCES = file_checker.c	\
	parser.c				\
	map.c					\
	solver.c				\
	main.c					\
	struct_init.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ make -s -C libft
	@ $(CC) -Llibft -lft -o $(NAME) $(OBJECTS)

clean:
	@ make -C libft clean
	@ rm -f $(OBJECTS)

fclean: clean
	@ make -C libft fclean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: $(OBJECTS)
