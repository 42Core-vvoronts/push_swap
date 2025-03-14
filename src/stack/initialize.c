/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:45:51 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:45:53 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * Gets valid input from argv.
 * @param argv The argument vector.
 * @param int_stack The integer stack.
 * @param len The length of the stack.
 * @return SUCCESS on success, FAIL on failure.
 */
int	get_valid_input(char **argv, int **int_stack, size_t *len)
{
	char	**str_stack;

	str_stack = get_valid_strings(argv);
	if (!str_stack)
		return (FAIL);
	*len = ft_parrlen(str_stack);
	*int_stack = get_valid_ints(str_stack, *len);
	ft_parrclean(0, free, str_stack, NULL);
	if (!*int_stack)
		return (FAIL);
	return (SUCCESS);
}

/**
 * Initializes stacks a and b from argv.
 * @param argv The argument vector.
 * @param a The stack a.
 * @param b The stack b.
 * @return SUCCESS on success, FAIL on failure.
 */
int	init_stacks(char **argv, t_stack *a, t_stack *b)
{
	int		*stack;
	int		exit_code;
	size_t	len;

	a->arr = NULL;
	b->arr = NULL;
	exit_code = get_valid_input(argv, &stack, &len);
	if (exit_code != SUCCESS)
		return (FAIL);
	a->arr = stack;
	a->max = len;
	a->len = a->max;
	a->head = 0;
	a->tail = a->max - 1;
	b->arr = (int *)malloc(sizeof(int) * len);
	b->max = a->max;
	b->len = 0;
	b->head = 0;
	b->tail = b->head;
	if (!b->arr)
		return (free(stack), FAIL);
	if (len == 1)
		return (LENONE);
	return (SUCCESS);
}
