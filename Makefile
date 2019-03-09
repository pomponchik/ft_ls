# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 03:51:55 by sbearded          #+#    #+#              #
#    Updated: 2019/03/04 16:24:53 by sbearded         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_ls

SRC =	read_dir.c \
		print.c \
		flags.c \
		main.c \
		print_time.c

OBJ =	read_dir.o \
		print.o \
		flags.o \
		main.o \
		print_time.o

WFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		gcc -g -c $(SRC)
		gcc -g -o $(NAME) $(OBJ) libft.a
clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
