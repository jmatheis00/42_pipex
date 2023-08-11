# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 19:33:15 by jmatheis          #+#    #+#              #
#    Updated: 2023/08/11 15:00:00 by jmatheis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= pipex
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g #-fsanitize=address -g

MAN_FILES	= src/commands.c \
			src/init_and_free.c \
			src/man_main.c \
			src/man_singlepipe.c

BON_FILES	= src/commands.c \
			src/init_and_free.c \
			src/bonus_main.c \
			src/bonus_pipes.c \
			src/bonus_childs.c

MAN_OBJ = $(MAN_FILES:.c=.o)

BON_OBJ = $(BON_FILES:.c=.o)

INCLUDES = incl/pipex.h

LIBS =	lib/printf/libftprintf.a \
		lib/libft/libft.a \
		lib/getnextline/getnextline.a

PRINTF = lib/printf
LIBFT = lib/libft
GNL = lib/getnextline

# ************* #
#     RULES     #
# ************* #

$(NAME): $(LIBS) $(MAN_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(MAN_OBJ) $(LIBS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBS) $(BON_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(BON_OBJ) $(LIBS)

lib/printf/libftprintf.a:
	@$(MAKE) -C $(PRINTF)

lib/libft/libft.a:
	@$(MAKE) -C $(LIBFT)

lib/getnextline/getnextline.a:
	@$(MAKE) -C $(GNL)

clean:
	rm -f src/*.o
	make fclean -C $(PRINTF)
	make fclean -C $(LIBFT)
	make fclean -C $(GNL)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

all: $(NAME)

.PHONY: bonus clean fclean re all