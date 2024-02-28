/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:58:24 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/23 15:11:26 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct number_stack
{
	int					num;
	struct number_stack	*next;
}						t_stack;

// CHECK PARAMS && GET NUMBERS
int						ft_atoi(char *s, t_stack **a);
int						ft_isdigit(char c);
int						ft_isspace(char c);
t_stack					*ft_split(char *s);
void					get_numbers(int ac, char **av, t_stack **a);

// STACK UTILS
t_stack					*new_node(int num);
t_stack					*ft_last(t_stack *lst);
int						stack_is_sorted(t_stack *a);
int						ft_stack_size(t_stack *lst);
void					ft_clear_lst(t_stack **lst);
int						get_target_pos(t_stack *a, int nbr);
int						get_current_pos(t_stack *b, int nbr);
void					add_at_end(t_stack **lst, t_stack *new);
void					add_at_front(t_stack **lst, t_stack *new);

// OPERATIONS
void					push(t_stack **a, t_stack **b, int mode);
void					swap_ops(t_stack **a, t_stack **b, int mode);
void					rotate_ops(t_stack **a, t_stack **b, int mode, int rev);

// SORTING UTILS
void					sort_two(t_stack **a);
void					sort_three(t_stack **a);
int						optimise_moves(int **moves);
int						calculate_moves(t_stack *s, int pos);
void					set_moves(t_stack *a, t_stack *b, int **moves);
void					move_stacks(t_stack **a, t_stack **b, int *moves);
void					exec_moves(t_stack **a, t_stack **b, int moves, int n);

// MEDIAN (QUICKSORT)
long					ft_abs(long n);
int						get_mdn(t_stack *a, int size_a);
int						*stack_to_arr(t_stack *a, int size);

// LONGEST INCREASING SEQUENCE
int						*ft_lis(t_stack *a, int n, int *lis_len);

// SORT STACK
void					sort_stack(t_stack **a, t_stack **b, int size_a);

// ERRORS
void					ft_error(t_stack **a);
void					ft_free(t_stack **a, t_stack **b, int *arr);

#endif