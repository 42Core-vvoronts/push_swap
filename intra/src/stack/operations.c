/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:45:56 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:45:59 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * Pushes the head element from src stack to dst stack.
 * @param src The source stack.
 * @param dst The destination stack.
 * @return PUSH on success, 0 if src stack is empty or dst is full
 * 
 * Increments len and moves head position of dst backwards on one physical index.
 * Sets element at the new head position.
 * Shifts head position of src forward and decrements the length of src.
 * 
 * @return PUSH on success, 0 if nothing or nowhere to push.
 * 
 */
int	push(t_stack *src, t_stack *dst)
{
	if (src->len == 0 && dst->len == dst->max)
		return (0);
	dst->len++;
	if (dst->len > 1)
		dst->head = wrap_pi(-1, dst, dst->head);
	dst->arr[dst->head] = src->arr[src->head];
	src->head = wrap_vi(1, src, src->head);
	src->len--;
	return (PUSH);
}

/**
 * Swaps the head two elements of the stack.
 * 
 * @param s The stack.
 * @return SWAP on success, 0 if stack has 1 or fewer elements.
 */
int	swap(t_stack *s)
{
	int	temp;
	int	next;

	if (s->len <= 1)
		return (0);
	temp = s->arr[s->head];
	next = wrap_vi(1, s, s->head);
	s->arr[s->head] = s->arr[next];
	s->arr[next] = temp;
	return (SWAP);
}

/**
 * Rotates the stack without shifting the elements.
 * @param s The stack.
 * 
 * Sets the head item to the tail position. 
 * 
 * @return ROTATE on success, 0 if stack is empty.
 */
int	rotate(t_stack *s)
{
	int	temp;

	if (s->len == 0 || s->len == 1)
		return (0);
	temp = s->arr[s->head];
	s->head = wrap_vi(1, s, s->head);
	s->tail = wrap_pi(1, s, s->tail);
	s->arr[s->tail] = temp;
	return (ROTATE);
}

/**
 * Reverse rotates the stack without shifting the elements.
 * 
 * @param s The stack.
 * 
 * Sets the tail item to the head position. 
 * 
 * @return REVERSE on success, 0 if stack is empty.
 */
int	reverse(t_stack *s)
{
	int	temp;

	if (s->len == 0 || s->len == 1)
		return (0);
	temp = s->arr[s->tail];
	s->tail = wrap_vi(-1, s, s->tail);
	s->head = wrap_pi(-1, s, s->head);
	s->arr[s->head] = temp;
	return (REVERSE);
}
