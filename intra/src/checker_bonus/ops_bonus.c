/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:42:13 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:42:16 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * Applies rotate command to the stacks.
 * @param cmd The command string.
 * @param a The stack a.
 * @param b The stack b.
 * @return ROTATE on success, FAIL on failure.
 */
int	apply_rotate(char *cmd, t_stack *a, t_stack *b)
{
	if (ft_strcmp(cmd, "ra\n") == 0)
		return (rotate(a));
	else if (ft_strcmp(cmd, "rb\n") == 0)
		return (rotate(b));
	else if (ft_strcmp(cmd, "rr\n") == 0)
	{
		rotate(a);
		return (rotate(b));
	}
	else
		return (FAIL);
}

/**
 * Applies reverse command to the stacks.
 * @param cmd The command string.
 * @param a The stack a.
 * @param b The stack b.
 * @return REVERSE on success, FAIL on failure.
 */
int	apply_reverse(char *cmd, t_stack *a, t_stack *b)
{
	if (ft_strcmp(cmd, "rra\n") == 0)
		return (reverse(a));
	else if (ft_strcmp(cmd, "rrb\n") == 0)
		return (reverse(b));
	else if (ft_strcmp(cmd, "rrr\n") == 0)
	{
		reverse(a);
		return (reverse(b));
	}
	else
		return (FAIL);
}

/**
 * Applies swap command to the stacks.
 * @param cmd The command string.
 * @param a The stack a.
 * @param b The stack b.
 * @return SWAP on success, FAIL on failure.
 */
int	apply_swap(char *cmd, t_stack *a, t_stack *b)
{
	if (ft_strcmp(cmd, "sa\n") == 0)
		return (swap(a));
	else if (ft_strcmp(cmd, "sb\n") == 0)
		return (swap(b));
	else if (ft_strcmp(cmd, "ss\n") == 0)
	{
		swap(a);
		return (swap(b));
	}
	else
		return (FAIL);
}

/**
 * Applies push command to the stacks.
 * @param cmd The command string.
 * @param a The stack a.
 * @param b The stack b.
 * @return PUSH on success, FAIL on failure.
 */
int	apply_push(char *cmd, t_stack *a, t_stack *b)
{
	if (ft_strcmp(cmd, "pa\n") == 0)
		return (push(b, a));
	else if (ft_strcmp(cmd, "pb\n") == 0)
		return (push(a, b));
	else
		return (FAIL);
}
