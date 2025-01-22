/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:43:16 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/09 09:51:19 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts the stack a using stack b. Choose between 
 * brutforce and quicksort methods depending on the stack size.
 * @param data contains both stacks and the list of commands.
 * 
 * @return The list of commands to sort the stack.
 */
void	sort(t_data *data)
{
	if (is_sorted(data->a))
		return ;
	if (data->a->len < 6)
		brutforce(data);
	else
		quicksort(data);
	optimize_cmds(data->cmds);
}
