/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:42:52 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:42:55 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Generates a command string based on op and stack.
 * @param op_id The op identifier.
 * @param stack The stack identifier.
 * @return The generated command string.
 */
char	*get_cmd(int op_id, int stack)
{
	char	*op;
	char	*letter;
	char	*cmd;

	if (op_id == ROTATE)
		op = "r";
	else if (op_id == REVERSE)
		op = "rr";
	else if (op_id == SWAP)
		op = "s";
	else
		op = "p";
	if (stack == A)
		letter = "a";
	else
		letter = "b";
	cmd = ft_strjoin(op, letter);
	if (!cmd)
		return (NULL);
	return (cmd);
}

/**
 * Logs a command to the command list.
 * @param op_id The op identifier.
 * @param stack The stack identifier.
 * @param cmds The command list.
 * @return 0 on success, FAIL on failure.
 */
void	log_cmd(int op_id, int stack, t_data *data)
{
	t_list	*node;
	char	*cmd;

	if (op_id == 0)
		return ;
	cmd = get_cmd(op_id, stack);
	if (!cmd)
		exit(MEMFAIL);
	node = ft_lstnew(cmd);
	if (!node)
	{
		ft_lstclear(data->cmds, free);
		free2(FAIL, cmd, NULL);
		free_stacks(data->a, data->b, FAIL);
		exit(MEMFAIL);
	}
	ft_lstadd_back(data->cmds, node);
}
