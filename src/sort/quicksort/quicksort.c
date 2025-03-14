/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:44:03 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:44:05 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Initialize quicksort. Sets first chunk to run recursive partitioning.
 * 
 * @param data struct with both stacks and commands.
 * 
 */
void	quicksort(t_data *data)
{
	t_chunk	initial;

	initial.loc = A_TOP;
	initial.len = data->a->len;
	partition(data, &initial);
}

/**
 * Recursivelly divides the stack in three parts and sorts them
 * 
 * @param data struct with both stacks and commands.
 * @param to_split The chunk to split into three parts.
 * 
 * Partition takes a chunk and splits it into max, mid and min parts 
 * and moves stacks content accordingly.
 * Continues splitting until each chunk will be small enough to sort 
 * with base case sorting.
 * 
 */
void	partition(t_data *data, t_chunk *to_split)
{
	t_parts	chunks;

	chunk_to_the_top(data, to_split);
	if (to_split->len <= 3)
		return (basecase_sort(data, to_split));
	split_chunk(data, to_split, &chunks);
	partition(data, &chunks.max);
	partition(data, &chunks.mid);
	partition(data, &chunks.min);
}

void	chunk_to_the_top(t_data *data, t_chunk *to_sort)
{
	if (to_sort->loc == A_BOT && data->a->len == to_sort->len)
		to_sort->loc = A_TOP;
	if (to_sort->loc == B_BOT && data->b->len == to_sort->len)
		to_sort->loc = B_TOP;
}
