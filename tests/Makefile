# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 15:51:25 by ipetrov           #+#    #+#              #
#    Updated: 2024/11/14 18:59:23 by ipetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

ARGS := 4 3 2 1

CFLAGS := -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): make
	@mv ../push_swap/push_swap ../tests/push_swap
	@mv ../push_swap/obj ../tests/

make: obj
	@mv ../tests/obj ../push_swap/
	@make -C ../push_swap/ CFLAGS="$(CFLAGS)"

obj:
	@mkdir -p obj

clean:
	@make clean -C ../push_swap/

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ../push_swap/

re: fclean all

# eval:

run: $(NAME)
	@./$(NAME) $(ARGS)

.PHONY: clean fclean re make
.DEFAULT_GOAL := all