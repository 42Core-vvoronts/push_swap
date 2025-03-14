/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:36:27 by vvoronts          #+#    #+#             */
/*   Updated: 2024/12/08 18:45:27 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

typedef enum Combined_operations
{
	none = 0,
	rr = 1,
	rrr = 2,
	ss = 3
}	t_cmbop;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_list	**cmds;

}	t_data;

typedef enum e_loc
{
	A_TOP,
	A_BOT,
	B_TOP,
	B_BOT
}	t_loc;

typedef struct s_chunk
{
	enum e_loc	loc;
	int			len;
}				t_chunk;

typedef struct s_parts
{
	t_chunk		max;
	t_chunk		mid;
	t_chunk		min;
}				t_parts;

// main
int		main(int argc, char **argv);
int		init_data(t_data *data, char **input);
// log commands
char	*get_cmd(int op_id, int stack);
void	log_cmd(int op_id, int stack, t_data *data);
// sort
void	sort(t_data *data);
// optimize commands
void	optimize_cmds(t_list **cmds);
bool	is_neutralizable(t_list *cmds);
bool	is_combinable(t_list *cmds, t_cmbop *op);
int		delete_pair(t_list *prv, t_list **cmds);
int		replace_pair(t_list *cmds, t_cmbop op);
// print commands
void	print_cmds(t_list *cmds);

//// Brutforce
void	brutforce(t_data *data);
void	sort_two(t_stack *s, t_data *data, int AB);
void	sort_three(t_stack *a, t_data *data);
void	sort_up_to_six(t_stack *a, t_stack *b, t_data *data);

// Quicksort
void	quicksort(t_data *data);
void	partition(t_data *data, t_chunk *to_split);
// Basecase
void	basecase_sort(t_data *data, t_chunk *rests);
void	sort_last_one(t_data *data, t_chunk *to_sort);
void	sort_last_two(t_data *data, t_chunk *to_sort);
void	sort_last_three(t_data *data, t_chunk *to_sort);
void	sort_a_top(t_data *data, t_chunk *to_sort, t_stack *a, int max);
void	sort_a_bot(t_data *data, t_chunk *to_sort, t_stack *a, int max);
void	sort_b_top(t_data *data, t_chunk *to_sort, t_stack *b, int max);
void	sort_b_bot(t_data *data, t_chunk *to_sort, t_stack *b, int max);
// Split
void	split_chunk(t_data *data, t_chunk *src, t_parts *dst);
void	set_location(enum e_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max);
void	innit_len(t_chunk *min, t_chunk *mid, t_chunk *max);
// Pivots
void	choose_pivots(t_data *data, t_chunk *src, int *pivmin, int *pivmax);
void	tmp_insertion_sort(int *arr, int left, int right);
// Move items
void	move_item(t_data *data, t_chunk *src, t_chunk *dst);
void	move_from_a_top(t_data *data, t_loc dst);
void	move_from_a_bot(t_data *data, t_loc dst);
void	move_from_b_top(t_data *data, t_loc dst);
void	move_from_b_bot(t_data *data, t_loc dst);
// In-sort optimization
void	chunk_to_the_top(t_data *data, t_chunk *to_sort);

// Utils
int		get_value(t_data *data, t_chunk *chunk, int steps);
int		get_min(t_stack *s);
int		get_next_min(t_stack *s, int min);
int		get_chunk_max(t_data *data, t_chunk *chunk);

#endif