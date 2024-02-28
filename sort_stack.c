/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:46:47 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/18 10:39:46 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *a)
{
	int	i;
	int	min;
	int	pos_min;

	i = 0;
	pos_min = -1;
	while (a)
	{
		if (pos_min == -1 || (a->num < min))
		{
			min = a->num;
			pos_min = i;
		}
		i++;
		a = a->next;
	}
	return (pos_min);
}

void	push_to_b(t_stack **a, t_stack **b, int *lis, int len)
{
	int	i;
	int	j;
	int	mdn;
	int	size_a;

	size_a = ft_stack_size(*a);
	mdn = get_mdn(*a, size_a);
	i = 0;
	j = 0;
	while (j < (size_a - len))
	{
		if (i >= len || (*a)->num != lis[i])
		{
			push(a, b, 2);
			if ((*b)->num <= mdn)
				rotate_ops(a, b, 2, 0);
			j++;
		}
		else
		{
			i++;
			rotate_ops(a, b, 1, 0);
		}
	}
	exec_moves(a, b, calculate_moves(*a, get_min(*a)), 0);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	int	*moves;

	moves = (int *)malloc(3 * sizeof(int));
	if (!moves)
		ft_free(a, b, 0);
	moves[0] = 0;
	moves[1] = 0;
	moves[2] = 0;
	while (ft_stack_size(*b) != 0)
	{
		set_moves(*a, *b, &moves);
		move_stacks(a, b, moves);
	}
	free(moves);
}

void	sort_stack(t_stack **a, t_stack **b, int size_a)
{
	int	*lis;
	int	len;

	if (size_a == 2)
		sort_two(a);
	else if (size_a == 3)
		sort_three(a);
	else if (size_a == 5)
	{
		push(a, b, 2);
		push(a, b, 2);
		sort_three(a);
		push_to_a(a, b);
		exec_moves(a, b, calculate_moves(*a, get_min(*a)), 0);
	}
	else
	{
		lis = ft_lis(*a, size_a, &len);
		if (!lis)
			ft_free(a, 0, 0);
		push_to_b(a, b, lis, len);
		free(lis);
		push_to_a(a, b);
		exec_moves(a, b, calculate_moves(*a, get_min(*a)), 0);
	}
}
