# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/08 10:41:09 by vvoronts          #+#    #+#              #
#    Updated: 2024/12/08 10:41:12 by vvoronts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the output library
NAME = elibft.a

# Source files
SRC := \
	ft_atoier.c \
	ft_parrlen.c \
	ft_parrjoin.c \
	ft_parrclean.c \
	ft_strcmp.c \
	ft_get_next_liner.c

# Object files
OBJ := $(SRC:%.c=obj/%.o)

# Dependency files
DEP = $(OBJ:obj/%.o=dep/%.d)

# Compiler flags
CFLAGS := -Wall -Wextra -Werror -g

all: $(NAME)
	@echo "Building $(NAME) ..."

# Rule to compile source files into object files
obj/%.o: src/%.c | dep obj
	@$(CC) $(CFLAGS) -I./include -MMD -MF dep/$(@:obj/%.o=%.d) -c $< -o $@

# Create obj directory if it doesn't exist
obj:
	@mkdir -p obj

# Create dep directory if it doesn't exist
dep:
	@mkdir -p dep

# Rule to create the library from object files
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

# Rule to clean object files
clean:
	@$(RM) $(OBJ)

# Rule to clean object files and the library
fclean:	clean
	@$(RM) $(NAME)

# Rule to rebuild everything
re:	fclean all

# Phony targets
.PHONY: all clean fclean re
# Default goal
.DEFAULT_GOAL := all
# Include dependency files
-include $(DEP)
