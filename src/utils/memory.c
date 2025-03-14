/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:46:28 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:46:29 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * Frees two pointers and returns a code.
 * @param code The code to return.
 * @param p1 The first pointer to free.
 * @param p2 The second pointer to free.
 * @return The code cast to long long.
 */
long long	free2(int code, void *p1, void *p2)
{
	free(p1);
	free(p2);
	return ((long long)code);
}

/**
 * Frees the stacks and returns an exit code.
 * @param a The stack a.
 * @param b The stack b.
 * @param exit_code The exit code.
 * @return The exit code.
 */
int	free_stacks(t_stack *a, t_stack *b, int exit_code)
{
	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
	return (exit_code);
}
