/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:42:58 by vvoronts          #+#    #+#             */
/*   Updated: 2025/01/26 11:18:01 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Main function for push_swap.
 * @param argc The argument count.
 * @param argv The argument vector.
 * @return SUCCESS on success, FAIL on failure.
 */
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		return (SUCCESS);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (FAIL);
	if ((init_data(data, ++argv)) == FAIL)
		return (free(data), FAIL);
	sort(data);
	print_cmds(*data->cmds);
	free_stacks(data->a, data->b, 0);
	free(data->cmds);
	free(data);
	return (SUCCESS);
}

/**
 * Initializes the data, command list and stacks.
 * Allocates heap memory for all.
 * @param data The argument count.
 * @param input The argv for stack a.
 * @return SUCCESS on success, FAIL on failure.
 */
int	init_data(t_data *data, char **input)
{
	t_stack	*a;
	t_stack	*b;
	t_list	**cmds;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		return (FAIL);
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		return (free_stacks(a, b, FAIL));
	if (init_stacks(input, a, b) != SUCCESS)
		return (free_stacks(a, b, FAIL));
	cmds = (t_list **)malloc(sizeof(t_list *));
	if (!cmds)
		return (free_stacks(a, b, FAIL));
	data->a = a;
	data->b = b;
	*cmds = NULL;
	data->cmds = cmds;
	return (SUCCESS);
}
