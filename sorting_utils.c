/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:04:33 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/17 13:48:50 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->num > (*a)->next->num)
		swap_ops(a, NULL, 1);
}

void	sort_three(t_stack **a)
{
	int	one;
	int	two;
	int	three;

	one = (*a)->num;
	two = (*a)->next->num;
	three = (*a)->next->next->num;
	if (one < two && two > three && one < three)
	{
		swap_ops(a, 0, 1);
		rotate_ops(a, 0, 1, 0);
	}
	if (one > two && two < three && one < three)
		swap_ops(a, 0, 1);
	if (one < two && two > three && one > three)
		rotate_ops(a, 0, 1, 1);
	if (one > two && two < three && one > three)
		rotate_ops(a, 0, 1, 0);
	if (one > two && two > three && one > three)
	{
		swap_ops(a, 0, 1);
		rotate_ops(a, 0, 1, 1);
	}
}

void	move_stacks(t_stack **a, t_stack **b, int *moves)
{
	exec_moves(a, b, moves[2], 2);
	exec_moves(a, b, moves[1], 1);
	exec_moves(a, b, moves[0], 0);
	push(a, b, 1);
}
