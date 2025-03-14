/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_last_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:44:08 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:44:10 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_top(t_data *data, t_chunk *to_sort, t_stack *a, int max)
{
	int	top;
	int	mid;

	top = get_value(data, to_sort, 0);
	mid = get_value(data, to_sort, 1);
	if (top == max)
	{
		log_cmd(swap(a), A, data);
		log_cmd(rotate(a), A, data);
		log_cmd(swap(a), A, data);
		log_cmd(reverse(a), A, data);
	}
	else if (mid == max)
	{
		log_cmd(rotate(a), A, data);
		log_cmd(swap(a), A, data);
		log_cmd(reverse(a), A, data);
	}
}

void	sort_b_top(t_data *data, t_chunk *to_sort, t_stack *b, int max)
{
	int	top;
	int	mid;

	top = get_value(data, to_sort, 0);
	mid = get_value(data, to_sort, 1);
	if (top == max)
		log_cmd(push(b, data->a), A, data);
	else if (mid == max)
	{
		log_cmd(swap(b), B, data);
		log_cmd(push(b, data->a), A, data);
	}
	else
	{
		log_cmd(rotate(b), B, data);
		log_cmd(swap(b), B, data);
		log_cmd(push(b, data->a), A, data);
		log_cmd(reverse(b), B, data);
	}
	log_cmd(push(b, data->a), A, data);
	log_cmd(push(b, data->a), A, data);
}

void	sort_a_bot(t_data *data, t_chunk *to_sort, t_stack *a, int max)
{
	int	top;
	int	mid;

	top = get_value(data, to_sort, 0);
	mid = get_value(data, to_sort, 1);
	log_cmd(reverse(a), A, data);
	if (top == max)
	{
		log_cmd(reverse(a), A, data);
		log_cmd(reverse(a), A, data);
	}
	else if (mid == max)
	{
		log_cmd(reverse(a), A, data);
		log_cmd(swap(a), A, data);
		log_cmd(reverse(a), A, data);
	}
	else
	{
		log_cmd(push(a, data->b), B, data);
		log_cmd(reverse(a), A, data);
		log_cmd(reverse(a), A, data);
		log_cmd(swap(a), A, data);
		log_cmd(push(data->b, a), A, data);
	}
}

// void	sort_b_bot(t_data *data, t_chunk *to_sort, t_stack *b, int max)
// {
// 	int	top;
// 	int	mid;

// 	top = get_value(data, to_sort, 0);
// 	mid = get_value(data, to_sort, 1);
// 	log_cmd(reverse(b), B, data);
// 	if (top == max)
// 	{
// 		log_cmd(push(b, data->a), A, data);
// 		log_cmd(reverse(b), B, data);
// 		log_cmd(push(b, data->a), A, data);
// 		log_cmd(reverse(b), B, data);
// 	}
// 	else if (mid == max)
// 	{
// 		log_cmd(reverse(b), B, data);
// 		log_cmd(push(b, data->a), A, data);
// 		log_cmd(reverse(b), B, data);
// 		log_cmd(push(b, data->a), A, data);
// 	}
// 	else
// 	{
// 		log_cmd(reverse(b), B, data);
// 		log_cmd(reverse(b), B, data);
// 		log_cmd(push(b, data->a), A, data);
// 		log_cmd(push(b, data->a), A, data);
// 	}
// 	log_cmd(push(b, data->a), A, data);
// }

void	sort_b_bot(t_data *data, t_chunk *to_sort, t_stack *b, int max)
{
	int	top;
	int	mid;

	top = get_value(data, to_sort, 0);
	mid = get_value(data, to_sort, 1);
	log_cmd(reverse(b), B, data);
	if (top == max)
		log_cmd(push(b, data->a), A, data);
	else
		log_cmd(reverse(b), B, data);
	if (top == max)
		log_cmd(reverse(b), B, data);
	else if (mid == max)
		log_cmd(push(b, data->a), A, data);
	else
	{
		log_cmd(reverse(b), B, data);
		log_cmd(push(b, data->a), A, data);
	}
	log_cmd(push(b, data->a), A, data);
	if (top == max || mid == max)
		log_cmd(reverse(b), B, data);
	log_cmd(push(b, data->a), A, data);
}
