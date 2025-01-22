/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:46:21 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:46:23 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * chunk_utils file contains supplementary functions to works with chunks
 * 
 * @define_stack: returns the stack by the location
 * @get_value: returns the value of chunk
 * @get_max_value: returns the max value of chunk
 * 
 */
int	get_value(t_data *data, t_chunk *chunk, int steps)
{
	t_stack	*stack;
	int		i;

	if (chunk->loc == A_TOP || chunk->loc == A_BOT)
		stack = data->a;
	else
		stack = data->b;
	if (chunk->loc == A_BOT || chunk->loc == B_BOT)
		steps = -1 + steps * (-1);
	i = wrap_vi(steps, stack, stack->head);
	return (stack->arr[i]);
}

/**
 * Searches for smallest element in given array
 * 
 * @param s The stack to search
 * @return smallest integer
 */
int	get_min(t_stack *s)
{
	int	min;
	int	i;

	i = 0;
	min = s->arr[wrap_vi(i, s, s->head)];
	while (++i < s->len)
	{
		if (s->arr[wrap_vi(i, s, s->head)] < min)
			min = s->arr[wrap_vi(i, s, s->head)];
	}
	return (min);
}

/**
 * Searches for next smallest element in given array
 * 
 * @param s The stack to search
 * @param min Smallest integer to compare
 * @return next smallest integer
 */
int	get_next_min(t_stack *s, int min)
{
	int	next_min;
	int	i;
	int	cur;

	i = wrap_vi(0, s, s->head);
	next_min = s->arr[i];
	while (++i < s->len)
	{
		cur = s->arr[wrap_vi(i, s, s->head)];
		if (next_min <= min)
			next_min = cur;
		if (cur < next_min && cur > min)
			next_min = cur;
	}
	return (next_min);
}

int	get_chunk_max(t_data *data, t_chunk *chunk)
{
	int		max;
	int		cur;
	int		i;

	i = 0;
	max = get_value(data, chunk, i);
	while (++i < chunk->len)
	{
		cur = get_value(data, chunk, i);
		if (cur > max)
			max = cur;
	}
	return (max);
}
