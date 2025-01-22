/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brutforce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:43:27 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:43:29 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts stack when size has small amount of elements.
 * 
 * @param data struct with both stacks and commands.
 * 
 * @return void
 */
void	brutforce(t_data *data)
{
	if (data->a->len == 2)
		sort_two(data->a, data, A);
	else if (data->a->len == 3)
		sort_three(data->a, data);
	else if (data->a->len >= 4 && data->a->len <= 6)
		sort_up_to_six(data->a, data->b, data);
}

/**
 * Sorts two elements by swap the top two elements of the stack.
 * 
 * @param data struct with both stacks and commands.
 * @param AB The stack to sort. A for stack A, B for stack B.
 * 
 * @return void
 */
void	sort_two(t_stack *s, t_data *data, int AB)
{
	if (s->len != 2)
		return ;
	if (s->arr[wrap_vi(0, s, s->head)] > s->arr[wrap_vi(1, s, s->head)])
		log_cmd(swap(s), AB, data);
}

/**
 * Sorts three elements. 
 * Sorts when number of elements is equal to actual array length.
 * and also when actual array length is greater.
 * 
 * @param data struct with both stacks and commands.
 * @param s The stack to sort.
 * 
 * @return void.
 */
void	sort_three(t_stack *s, t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	if (s->len != 3)
		return ;
	top = s->arr[wrap_vi(0, s, s->head)];
	mid = s->arr[wrap_vi(1, s, s->head)];
	bot = s->arr[wrap_vi(-1, s, s->head)];
	if (top > mid && bot > mid && bot > top)
		log_cmd(swap(s), A, data);
	else if (top > mid && bot > mid && top > bot)
		log_cmd(rotate(s), A, data);
	else if (mid > top && mid > bot && top > bot)
		log_cmd(reverse(s), A, data);
	else if (mid > top && mid > bot && bot > top)
	{
		log_cmd(swap(s), A, data);
		log_cmd(rotate(s), A, data);
	}
	else if (top > mid && mid > bot && top > bot)
	{
		log_cmd(swap(s), A, data);
		log_cmd(reverse(s), A, data);
	}
}

/**
 * Sorts four-six elements.
 * 
 * @param data struct with both stacks and commands.
 * @param a The stack to sort.
 * @param b Supplementary stack.
 * 
 * @return void.
 */
void	sort_up_to_six(t_stack *a, t_stack *b, t_data *data)
{
	int	min;

	min = get_min(a);
	if (a->len >= 5)
		min = get_next_min(a, min);
	if (a->len == 6)
		min = get_next_min(a, min);
	while (a->len > 3)
	{
		if (a->arr[wrap_vi(0, a, a->head)] <= min)
			log_cmd(push(a, b), B, data);
		else
			log_cmd(rotate(a), A, data);
	}
	sort_three(a, data);
	sort_three(b, data);
	sort_two(b, data, B);
	while (b->len > 0)
	{
		log_cmd(reverse(b), B, data);
		log_cmd(push(b, a), A, data);
	}
}
