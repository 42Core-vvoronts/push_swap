/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:42:02 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:42:05 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		exit_code;

	if (argc == 1)
		return (0);
	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		return (FAIL);
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		return (free_stacks(a, b, FAIL));
	exit_code = init_stacks(++argv, a, b);
	if (exit_code < 0 && exit_code != LENONE)
		return (free_stacks(a, b, FAIL));
	if (process_cmds(a, b) != SUCCESS)
		return (free_stacks(a, b, FAIL));
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (free_stacks(a, b, SUCCESS));
}
