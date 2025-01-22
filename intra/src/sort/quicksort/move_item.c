/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:43:57 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:43:59 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Move items between logical chunks.
 * 
 * @param data struct with both stacks and commands.
 * @param src source chunk.
 * @param dst destination chunk.
 * 
 * Defines the location of the source and destination chunks.
 * Calls the appropriate function to move the item.
 * Updates the length of the source and destination chunks.
 */
void	move_item(t_data *data, t_chunk *src, t_chunk *dst)
{
	if (src->loc == A_TOP)
		move_from_a_top(data, dst->loc);
	else if (src->loc == A_BOT)
		move_from_a_bot(data, dst->loc);
	else if (src->loc == B_TOP)
		move_from_b_top(data, dst->loc);
	else if (src->loc == B_BOT)
		move_from_b_bot(data, dst->loc);
	dst->len++;
	src->len--;
}

void	move_from_a_top(t_data *data, t_loc dst)
{
	if (dst == B_TOP)
		log_cmd(push(data->a, data->b), B, data);
	else if (dst == A_BOT)
		log_cmd(rotate(data->a), A, data);
	else if (dst == B_BOT)
	{
		log_cmd(push(data->a, data->b), B, data);
		log_cmd(rotate(data->b), B, data);
	}
}

void	move_from_a_bot(t_data *data, t_loc dst)
{
	if (dst == A_TOP)
		log_cmd(reverse(data->a), A, data);
	else if (dst == B_TOP)
	{
		log_cmd(reverse(data->a), A, data);
		log_cmd(push(data->a, data->b), B, data);
	}
	else if (dst == B_BOT)
	{
		log_cmd(reverse(data->a), A, data);
		log_cmd(push(data->a, data->b), B, data);
		log_cmd(rotate(data->b), B, data);
	}
}

void	move_from_b_top(t_data *data, t_loc dst)
{
	if (dst == A_TOP)
		log_cmd(push(data->b, data->a), A, data);
	else if (dst == B_BOT)
		log_cmd(rotate(data->b), B, data);
	else if (dst == A_BOT)
	{
		log_cmd(push(data->b, data->a), A, data);
		log_cmd(rotate(data->a), A, data);
	}
}

void	move_from_b_bot(t_data *data, t_loc dst)
{
	if (dst == B_TOP)
		log_cmd(reverse(data->b), B, data);
	else if (dst == A_TOP)
	{
		log_cmd(reverse(data->b), B, data);
		log_cmd(push(data->b, data->a), A, data);
	}
	else if (dst == A_BOT)
	{
		log_cmd(reverse(data->b), B, data);
		log_cmd(push(data->b, data->a), A, data);
		log_cmd(rotate(data->a), A, data);
	}
}
