# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/08 10:37:31 by vvoronts          #+#    #+#              #
#    Updated: 2024/12/08 10:37:33 by vvoronts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -g -MMD -MF
RM					=	rm -rf
NAME				=	push_swap
BONUS_NAME			=	checker


INCLUDE_DIRS		=	./include \
						./lib/libft \
						./lib/elibft/include \
						./lib/ft_printf \

VPATH				=	./src/push_swap:\
						./src/stack:\
						./src/utils:\
						./src/sort/brutforce:\
						./src/sort/quicksort:\
						./src/checker_bonus:\

INCLUDE				=	$(addprefix -I, $(INCLUDE_DIRS))

SHARED_SRC			= 	validate.c \
						initialize.c \
						operations.c \
						validate_ints.c \
						validate_strings.c \
						wrap_index.c \
						memory.c \

MANDATORY_SRC 		=	$(SHARED_SRC) \
						main.c \
						log.c \
						optimize.c \
						print.c \
						sort.c \
						brutforce.c \
						basecase.c \
						choose_pivots.c \
						move_item.c \
						quicksort.c \
						sort_last_three.c \
						split_chunks.c \
						get_values.c \

BONUS_SRC 			=	$(SHARED_SRC) \
						main_bonus.c \
						ops_bonus.c \
						process_bonus.c \

LIBS 				=	./lib/libft/libft.a \
						./lib/ft_printf/ft_printf.a \
						./lib/elibft/elibft.a \

MANDATORY_OBJ		=	$(MANDATORY_SRC:%.c=obj/$(NAME)/%.o)
BONUS_OBJ			= 	$(BONUS_SRC:%.c=obj/$(BONUS_NAME)/%.o)

DEP					=	$(MANDATORY_SRC:%.c=dep/%.d) $(BONUS_SRC:%.c=dep/%.d)

MFLAGS				= --no-print-directory -C

a: all bonus

all: $(NAME)
	@echo "Building $(NAME) ..."

bonus: $(BONUS_NAME)
	@echo "Building $(BONUS_NAME) ..."

$(NAME): $(MANDATORY_OBJ) libs
	@$(CC) $(MANDATORY_OBJ) $(LIBS) -o $@

$(BONUS_NAME): $(BONUS_OBJ) libs
	@$(CC) $(BONUS_OBJ) $(LIBS) -o $@

libs:
	@make $(MFLAGS) ./lib/libft
	@make $(MFLAGS) ./lib/ft_printf
	@make $(MFLAGS) ./lib/elibft

obj/$(NAME)/%.o: %.c | mandatory_dep mandatory_obj_dir
	@$(CC) $(CFLAGS) dep/$(@:obj/%.o=%.d) $(INCLUDE) -c $< -o $@

obj/$(BONUS_NAME)/%.o: %.c | bonus_dep bonus_obj_dir
	@$(CC) $(CFLAGS) dep/$(@:obj/%.o=%.d) $(INCLUDE) -c $< -o $@

mandatory_obj_dir:
	@mkdir -p obj
	@mkdir -p obj/$(NAME)

bonus_obj_dir:
	@mkdir -p obj
	@mkdir -p obj/$(BONUS_NAME)

mandatory_dep:
	@mkdir -p dep
	@mkdir -p dep/$(NAME)

bonus_dep:
	@mkdir -p dep
	@mkdir -p dep/$(BONUS_NAME)

clean:
	@echo "Cleaning ..."
	@$(RM) obj
	@$(RM) dep
	@make clean $(MFLAGS) ./lib/libft
	@make clean $(MFLAGS) ./lib/ft_printf
	@make clean $(MFLAGS) ./lib/elibft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@make fclean $(MFLAGS) ./lib/libft
	@make fclean $(MFLAGS) ./lib/ft_printf
	@make fclean $(MFLAGS) ./lib/elibft

re: fclean a

.PHONY: all clean fclean re bonus libs a
.DEFAULT_GOAL := a

# Include the dependency files
# -include