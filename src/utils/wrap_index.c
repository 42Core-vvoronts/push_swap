/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:46:54 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:46:56 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Wraps virtual indexes limited by len, avoid out of bounds.
 * Handles the overlapping and moving backwards.
 * @param s The stack to interate
 * @param vi virtual index aka number and direction of steps 
 * vi = -1 means 1 index back
 * @param vizero virtual start, can be head or tail
 * 
 * @return The physical index steps equivalent to the virtual index vi
 */
int	wrap_vi(int steps, t_stack *s, int vizero)
{
	int	shift;

	if (s->len == 0)
		return (0);
	shift = 0;
	if (steps % s->len == 0)
		return (vizero);
	if (vizero == s->head && steps < 0)
		shift = s->len;
	else if (vizero == s->tail && steps < 0)
		shift = s->max;
	else if (vizero == s->tail && steps > 0)
	{
		steps -= 1;
		vizero = s->head;
	}
	return ((vizero + (steps % s->len) + shift) % s->max);
}

/**
 * Wraps physical indexes around the whole circular array ignoring len.
 * Handles the overlapping and moving backwards.
 * @param s The stack to interate
 * @param steps number and direction of steps, -1 means 1 index back
 * @param vizero virtual start, can be head or tail
 * 
 * @return The physical index steps equivalent to the virtual index vi
 */
int	wrap_pi(int steps, t_stack *s, int vizero)
{
	int	index;

	index = (vizero + steps) % s->max;
	if (index < 0)
		index += s->max;
	return (index);
}
