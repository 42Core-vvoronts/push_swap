# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 16:48:06 by ipetrov           #+#    #+#              #
#    Updated: 2024/11/17 17:55:13 by ipetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c


BSRCS := ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
	ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJS := $(SRCS:.c=.o)
BOBJS := $(BSRCS:.c=.o)
DEPS := libft.h

CFLAGS := -Wall -Wextra -Werror

a: all bonus
	@echo "Building $(NAME) ..."

all: $(NAME)

%.o: %.c $(DEPS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BOBJS)
	@ar rcs $(NAME) $(OBJS) $(BOBJS)

clean:
	@$(RM) $(OBJS) $(BOBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
.DEFAULT_GOAL := a