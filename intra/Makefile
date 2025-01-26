# Compilation and flags
CC					=	cc
RM					=	rm -rf
CFLAGS				=	-Wall -Wextra -Werror -g -MMD -MF
MFLAGS				=	-C
# Program name
NAME				=	push_swap
BONUS_NAME			=	checker

# Directories and paths
INCLUDE_DIRS		=	./include \
						./lib/include

VPATH				=	./src/push_swap: \
						./src/stack: \
						./src/utils: \
						./src/sort/brutforce: \
						./src/sort/quicksort: \
						./src/checker_bonus: \

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

LIBS 				=	./lib/libft.a \

MANDATORY_OBJ		=	$(MANDATORY_SRC:%.c=obj/$(NAME)/%.o)
BONUS_OBJ			= 	$(BONUS_SRC:%.c=obj/$(BONUS_NAME)/%.o)

DEP					=	$(MANDATORY_SRC:%.c=dep/%.d) $(BONUS_SRC:%.c=dep/%.d)

# Make mandatory and bonus 
all: $(NAME) libs bonus
	@echo "$(GREEN)Making $(NAME)...$(RESET)"

bonus: $(BONUS_NAME)
	@echo "$(GREEN)Making $(BONUS_NAME)...$(RESET)"

$(NAME): $(MANDATORY_OBJ)
	@$(CC) $(MANDATORY_OBJ) $(LIBS) -o $@

$(BONUS_NAME): $(BONUS_OBJ)
	@$(CC) $(BONUS_OBJ) $(LIBS) -o $@

libs:
	@echo "$(GREEN)Making library...$(RESET)"
	@make $(MFLAGS) ./lib

# Object file for mandatory part
obj/$(NAME)/%.o: %.c | mandatory_dep mandatory_obj_dir
	@$(CC) $(CFLAGS) dep/$(@:obj/%.o=%.d) $(INCLUDE) -c $< -o $@

# Object file for bonus part
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

# Clean mandatiry part
clean:
	@echo "$(YELLOW)Removing push_swap objects and deps...$(RESET)"
	@$(RM) obj/$(NAME)
	@$(RM) dep/$(NAME)
	@echo "$(YELLOW)Removing bonus objects and deps...$(RESET)"
	@$(RM) obj/$(BONUS_NAME)
	@$(RM) dep/$(BONUS_NAME)

# Clean libs
cleanlib:
	@echo "$(YELLOW)Cleaning library...$(RESET)"
	@make clean $(MFLAGS) ./lib

fclean: clean cleanlib
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) has been removed.$(RESET)"
	@$(RM) $(BONUS_NAME)
	@echo "$(RED)$(BONUS_NAME) has been removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
.DEFAULT_GOAL := all

# Include the dependency files
-include $(DEP)

# set colors
RED					= 	\033[0;31m
GREEN				= 	\033[0;32m
YELLOW				= 	\033[0;33m
RESET				= 	\033[0m