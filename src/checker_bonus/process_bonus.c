/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:42:21 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/09 11:18:30 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * Applies a command to the stacks.
 * @param cmd The command string.
 * @param a The stack a.
 * @param b The stack b.
 * @return SUCCESS on success, FAIL on failure.
 */
int	apply_cmd(char **cmd, t_stack *a, t_stack *b)
{
	if (apply_rotate(*cmd, a, b) != FAIL)
		;
	else if (apply_reverse(*cmd, a, b) != FAIL)
		;
	else if (apply_swap(*cmd, a, b) != FAIL)
		;
	else if (apply_push(*cmd, a, b) != FAIL)
		;
	else
	{
		write(STDERR_FILENO, "Error\n", 6);
		free(*cmd);
		return (FAIL);
	}
	free(*cmd);
	cmd = NULL;
	return (SUCCESS);
}

/**
 * Reads a command from stdin.
 * @param cmd The command string.
 * @return SUCCESS on success, FAIL on failure.
 */
int	read_cmd(char **cmd)
{
	int	error;

	*cmd = get_next_liner(STDIN_FILENO, &error);
	if (error != SUCCESS)
	{
		free(*cmd);
		*cmd = NULL;
		return (FAIL);
	}
	return (SUCCESS);
}

/**
 * Processes commands from stdin and applies them to the stacks.
 * @param a The stack a.
 * @param b The stack b.
 * @return SUCCESS on success, FAIL on failure.
 */
int	process_cmds(t_stack *a, t_stack *b)
{
	char	*cmd;

	while (1)
	{
		if (read_cmd(&cmd) != SUCCESS)
			return (FAIL);
		if (!cmd)
			return (SUCCESS);
		if (apply_cmd(&cmd, a, b) != SUCCESS)
			return (FAIL);
	}
}
