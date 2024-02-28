/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:42:58 by anass             #+#    #+#             */
/*   Updated: 2024/02/28 14:34:35 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct number_stack
{
	int					num;
	struct number_stack	*next;
}						t_stack;

// PUSH_SWAP FUNCTIONS
void					get_numbers(int ac, char **av, t_stack **a);

// STACK UTILS
void					add_at_front(t_stack **lst, t_stack *new);
int						stack_is_sorted(t_stack *a);
int						ft_stack_size(t_stack *lst);
void					ft_clear_lst(t_stack **lst);
t_stack					*ft_last(t_stack *lst);

// OPERATIONS
void					push(t_stack **a, t_stack **b, int mode);
void					swap_ops(t_stack **a, t_stack **b, int mode);
void					rotate_ops(t_stack **a, t_stack **b, int mode, int rev);

// CHECKER FUNTIONS
void					exec_instruction(char *instruction, t_stack **a,
							t_stack **b);

// GNL
char					*get_next_line(int fd);

#endif