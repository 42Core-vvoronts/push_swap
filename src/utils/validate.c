/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:46:32 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:46:36 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * Checks if the stack is sorted.
 * @param s The stack.
 * @return true if the stack is sorted, false otherwise.
 */

bool	is_sorted(t_stack *s)
{
	int	i;
	int	len;
	int	cur;
	int	nxt;

	if (s->len != s->max)
		return (false);
	i = 0;
	len = s->len - 1;
	while (len--)
	{
		cur = s->arr[wrap_vi(i, s, s->head)];
		nxt = s->arr[wrap_vi(i + 1, s, s->head)];
		if (cur > nxt)
			return (false);
		i++;
	}
	return (true);
}
