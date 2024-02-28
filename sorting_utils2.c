/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:36:16 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/18 10:39:30 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_moves(t_stack *s, int pos)
{
	int	size_s;

	size_s = ft_stack_size(s);
	if (pos == size_s)
		return (0);
	if (pos <= (size_s / 2))
		return (pos);
	else
		return (pos - size_s);
}

int	optimise_moves(int **moves)
{
	if (moves[0][0] && moves[0][1] && moves[0][0] * moves[0][1] > 0)
	{
		if (moves[0][0] < moves[0][1])
		{
			moves[0][2] = moves[0][0];
			moves[0][1] -= moves[0][0];
			moves[0][0] = 0;
		}
		else
		{
			moves[0][2] = moves[0][1];
			moves[0][0] -= moves[0][1];
			moves[0][1] = 0;
		}
	}
	return (abs(moves[0][0]) + abs(moves[0][1]) + abs(moves[0][2]));
}

void	set_moves_helper(int **moves, int a, int b, int ab)
{
	moves[0][0] = a;
	moves[0][1] = b;
	moves[0][2] = ab;
}

void	set_moves(t_stack *a, t_stack *b, int **moves)
{
	t_stack	*s;
	int		pos_a;
	int		pos_b;
	int		total;
	int		*cur_mv;

	cur_mv = (int *)malloc(sizeof(int) * 3);
	if (!cur_mv)
		ft_free(&a, &b, *moves);
	total = -1;
	s = b;
	while (b)
	{
		pos_a = get_target_pos(a, b->num);
		pos_b = get_current_pos(s, b->num);
		set_moves_helper(&cur_mv, calculate_moves(a, pos_a), calculate_moves(s,
				pos_b), 0);
		if (total == -1 || optimise_moves(&cur_mv) < total)
		{
			set_moves_helper(moves, cur_mv[0], cur_mv[1], cur_mv[2]);
			total = optimise_moves(moves);
		}
		b = b->next;
	}
	free(cur_mv);
}

void	exec_moves(t_stack **a, t_stack **b, int moves, int n)
{
	while (moves > 0)
	{
		rotate_ops(a, b, n + 1, 0);
		moves--;
	}
	while (moves < 0)
	{
		rotate_ops(a, b, n + 1, 1);
		moves++;
	}
}
