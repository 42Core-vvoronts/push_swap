/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:43:04 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:43:07 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Replaces a pair of commands with a combined command.
 *
 * @param cmds The list of commands.
 * @param op The combined operation to replace with.
 * @return SUCCESS if the replacement was successful, otherwise FAIL.
 */
int	replace_pair(t_list *cmds, t_cmbop op)
{
	t_list	*tmp;
	char	*cmd;

	free(cmds->content);
	free(cmds->next->content);
	tmp = cmds->next;
	cmds->next = cmds->next->next;
	free(tmp);
	if (op == rr)
		cmd = ft_strdup("rr");
	else if (op == rrr)
		cmd = ft_strdup("rrr");
	else if (op == ss)
		cmd = ft_strdup("ss");
	else
		cmd = NULL;
	if (!cmd)
		return (FAIL);
	cmds->content = cmd;
	return (SUCCESS);
}

/**
 * Checks if a pair of commands can be combined into a single command.
 * ra + rb = rr
 * rb + ra = rr
 * rra + rrb = rrr
 * rrb + rra = rrr
 * sa + sb = ss
 * sb + sa = ss
 * @param cmds The list of commands.
 * @param op Pointer to store the combined operation if combinable.
 * @return true if the commands can be combined, otherwise false.
 */
bool	is_combinable(t_list *cmds, t_cmbop *op)
{
	char	*cmd1;
	char	*cmd2;

	if (!cmds)
		return (false);
	if (!cmds->next)
		return (false);
	cmd1 = cmds->content;
	cmd2 = cmds->next->content;
	*op = none;
	if (ft_strcmp("ra", cmd1) == 0 && ft_strcmp("rb", cmd2) == 0)
		*op = rr;
	else if (ft_strcmp("rb", cmd1) == 0 && ft_strcmp("ra", cmd2) == 0)
		*op = rr;
	else if (ft_strcmp("rra", cmd1) == 0 && ft_strcmp("rrb", cmd2) == 0)
		*op = rrr;
	else if (ft_strcmp("rrb", cmd1) == 0 && ft_strcmp("rra", cmd2) == 0)
		*op = rrr;
	else if (ft_strcmp("sa", cmd1) == 0 && ft_strcmp("sb", cmd2) == 0)
		*op = ss;
	else if (ft_strcmp("sb", cmd1) == 0 && ft_strcmp("sa", cmd2) == 0)
		*op = ss;
	if (*op == none)
		return (false);
	return (true);
}

/**
 * Deletes a pair of neutralizing commands from the list.
 *
 * @param prv The previous command in the list.
 * @param cmds The list of commands.
 * @return SUCCESS if the deletion was successful.
 */
int	delete_pair(t_list *prv, t_list **cmds)
{
	t_list	*cmd2;
	t_list	*nxt;

	cmd2 = (*cmds)->next;
	nxt = cmd2->next;
	free((*cmds)->content);
	free(*cmds);
	free(cmd2->content);
	free(cmd2);
	if (prv)
		prv->next = nxt;
	else
		*cmds = nxt;
	return (SUCCESS);
}

/**
 * Checks if a pair of commands neutralize each other.
 * ra + rra = 0
 * rra + ra = 0
 * rb + rrb = 0
 * rrb + rb = 0
 * sa + sa = 0
 * sb + sb = 0
 * pa + pb = 0
 * pb + pa = 0
 * @param cmds The list of commands.
 * @return true if the commands neutralize each other, otherwise false.
 */
bool	is_neutralizable(t_list *cmds)
{
	char	*cmd1;
	char	*cmd2;

	if (!cmds || !cmds->next)
		return (false);
	cmd1 = cmds->content;
	cmd2 = cmds->next->content;
	if (ft_strcmp("ra", cmd1) == 0 && ft_strcmp("rra", cmd2) == 0)
		return (true);
	else if (ft_strcmp("rra", cmd1) == 0 && ft_strcmp("ra", cmd2) == 0)
		return (true);
	else if (ft_strcmp("rb", cmd1) == 0 && ft_strcmp("rrb", cmd2) == 0)
		return (true);
	else if (ft_strcmp("rrb", cmd1) == 0 && ft_strcmp("rb", cmd2) == 0)
		return (true);
	else if (ft_strcmp("sa", cmd1) == 0 && ft_strcmp("sa", cmd2) == 0)
		return (true);
	else if (ft_strcmp("sb", cmd1) == 0 && ft_strcmp("sb", cmd2) == 0)
		return (true);
	else if (ft_strcmp("pa", cmd1) == 0 && ft_strcmp("pb", cmd2) == 0)
		return (true);
	else if (ft_strcmp("pb", cmd1) == 0 && ft_strcmp("pa", cmd2) == 0)
		return (true);
	return (false);
}

/**
 * Optimizes the list of commands by combining or neutralizing pairs of commands.
 *
 * @param cmds The list of commands.
 * @return The optimized list of commands.
 */
void	optimize_cmds(t_list **cmds)
{
	t_cmbop	op;
	t_list	*prv;
	t_list	**cur;

	if (!cmds || !*cmds || !(*cmds)->next)
		return ;
	while (is_neutralizable(*cmds))
		delete_pair(NULL, cmds);
	cur = cmds;
	prv = NULL;
	while (*cur)
	{
		if (is_combinable(*cur, &op))
		{
			if (replace_pair(*cur, op) != SUCCESS)
				return ;
		}
		else if (is_neutralizable(*cur))
			delete_pair(prv, cur);
		prv = *cur;
		if (*cur)
			cur = &(*cur)->next;
	}
}
