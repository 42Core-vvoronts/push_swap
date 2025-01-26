/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:36:37 by vvoronts          #+#    #+#             */
/*   Updated: 2025/01/22 15:27:04 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# include "libft.h"
# include "elibft.h"
# include "ft_printf.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

# define LENONE -3
# define MEMFAIL -2
# define FAIL -1
# define SUCCESS 0
# define A 0
# define B 1
# define ROTATE 1
# define REVERSE 2
# define SWAP 3
# define PUSH 4

// Circular buffer stack
typedef struct s_stack
{
	int	*arr;
	int	head;
	int	tail;
	int	len;
	int	max;

}	t_stack;

// Operations
int			push(t_stack *src, t_stack *dst);
int			swap(t_stack *s);
int			rotate(t_stack *s);
int			reverse(t_stack *s);
// stack
int			init_stacks(char **argv, t_stack *a, t_stack *b);
int			get_valid_input(char **argv, int **int_stack, size_t *len);
bool		is_duplicate_in_array(int *arr, size_t len);
int			*get_valid_ints(char **str_stack, size_t len);
bool		is_only_spaces_str(char *str);
bool		is_empty_str(char *str);
bool		is_valid_str(char *str);
char		**get_valid_strings(char **argv);
// utils
bool		is_sorted(t_stack *s);
int			wrap_vi(int vi, t_stack *s, int vizero);
int			wrap_pi(int pi, t_stack *s, int vizero);
long long	free2(int code, void *p1, void *p2);
int			free_stacks(t_stack *a, t_stack *b, int exit_code);

#endif
