/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:43:10 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:43:13 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Prints the commands in the list. And clear entire list.
 * @param cmds The command list.
 */
void	print_cmds(t_list *cmds)
{
	t_list	*mem;

	mem = cmds;
	while (cmds)
	{
		ft_printf("%s\n", cmds->content);
		cmds = cmds->next;
	}
	ft_lstclear(&mem, free);
}
