/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:44:21 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 18:45:22 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** 
 * split_chunk - splits the chunk into 3 logical chunks for further sorting
 * @data: contains both stacks and the list of commands
 * @src: the chunk to split
 * @dst: the result partition to split the chunk into
 * @pivmin: pointer to store the first pivot
 * @pivmax: pointer to store the second pivot
 * 
 * split_chunk will create partitions and save logs to struct s_partition
 * meta info about where logical partitions are located
 * stacks a and b are modified
 */
void	split_chunk(t_data *data, t_chunk *src, t_parts *dst_parts)
{
	int		pivmin;
	int		pivmax;
	int		value;
	t_chunk	*dst;

	innit_len(&dst_parts->min, &dst_parts->mid, &dst_parts->max);
	set_location(src->loc, &dst_parts->min, &dst_parts->mid, &dst_parts->max);
	choose_pivots(data, src, &pivmin, &pivmax);
	while (src->len)
	{
		value = get_value(data, src, 0);
		if (value < pivmin)
			dst = &dst_parts->min;
		else if (value <= pivmax)
			dst = &dst_parts->mid;
		else
			dst = &dst_parts->max;
		move_item(data, src, dst);
	}
}

// move_workbench 
void	set_location(enum e_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (loc == A_TOP)
	{
		min->loc = B_BOT;
		mid->loc = B_TOP;
		max->loc = A_BOT;
	}
	else if (loc == A_BOT)
	{
		min->loc = B_BOT;
		mid->loc = B_TOP;
		max->loc = A_TOP;
	}
	else if (loc == B_TOP)
	{
		min->loc = B_BOT;
		mid->loc = A_BOT;
		max->loc = A_TOP;
	}
	else if (loc == B_BOT)
	{
		min->loc = B_TOP;
		mid->loc = A_BOT;
		max->loc = A_TOP;
	}
}

void	innit_len(t_chunk *min, t_chunk *mid, t_chunk *max)
{
	min->len = 0;
	mid->len = 0;
	max->len = 0;
}
