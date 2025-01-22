/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basecase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:43:44 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:43:46 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Takes rest of the stack and sorts it with size-suitable function
 * 
 * @param data struct with both stacks and commands.
 * @param rests The chunk to sort
 * 
 */
void	basecase_sort(t_data *data, t_chunk *rests)
{
	if (rests->len == 3)
		sort_last_three(data, rests);
	else if (rests->len == 2)
		sort_last_two(data, rests);
	else if (rests->len == 1)
		sort_last_one(data, rests);
	return ;
}

void	sort_last_one(t_data *data, t_chunk *rests)
{
	t_chunk	atop;

	atop.loc = A_TOP;
	atop.len = data->a->len;
	if (rests->loc != A_TOP)
		move_item(data, rests, &atop);
	rests->len = 0;
}

void	sort_last_two(t_data *data, t_chunk *rests)
{
	t_chunk	atop;

	atop.loc = A_TOP;
	atop.len = data->a->len;
	if (rests->loc != A_TOP)
	{
		move_item(data, rests, &atop);
		move_item(data, rests, &atop);
	}
	if (get_value(data, &atop, 0) > get_value(data, &atop, 1))
		log_cmd(swap(data->a), A, data);
	rests->len = 0;
}

void	sort_last_three(t_data *data, t_chunk *to_sort)
{
	t_stack		*s;
	int			max;

	if (to_sort->loc == A_TOP || to_sort->loc == A_BOT)
		s = data->a;
	else
		s = data->b;
	max = get_chunk_max(data, to_sort);
	if (to_sort->loc == A_TOP)
		sort_a_top(data, to_sort, s, max);
	else if (to_sort->loc == A_BOT)
		sort_a_bot(data, to_sort, s, max);
	else if (to_sort->loc == B_TOP)
		sort_b_top(data, to_sort, s, max);
	else if (to_sort->loc == B_BOT)
		sort_b_bot(data, to_sort, s, max);
	to_sort->loc = A_TOP;
	to_sort->len -= 1;
	sort_last_two(data, to_sort);
}
