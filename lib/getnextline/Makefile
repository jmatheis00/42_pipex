# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 14:02:01 by jmatheis          #+#    #+#              #
#    Updated: 2022/10/11 14:01:03 by jmatheis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	getnextline.a
CFLAGS		= -Wall -Werror -Wextra
CC			= cc
MAIN = 	get_next_line.c \
		get_next_line_utils.c

mains = $(MAIN:.c=.o)

$(NAME): $(mains)
	ar -rs $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	
clean:
	rm -f *.o

all: $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all