/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:35:05 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 10:35:11 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "shared.h"

int	main(int argc, char **argv);
int	process_cmds(t_stack *a, t_stack *b);
int	read_cmd(char **cmd);
int	apply_cmd(char **cmd, t_stack *a, t_stack *b);
int	apply_rotate(char *cmd, t_stack *a, t_stack *b);
int	apply_reverse(char *cmd, t_stack *a, t_stack *b);
int	apply_swap(char *cmd, t_stack *a, t_stack *b);
int	apply_push(char *cmd, t_stack *a, t_stack *b);
#endif