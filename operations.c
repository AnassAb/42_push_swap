/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabidar <aabidar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:01:38 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/12 09:01:57 by aabidar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **lst)
{
	t_stack	*tmp;

	if (ft_stack_size(*lst) >= 2)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		tmp->next = (*lst)->next;
		(*lst)->next = tmp;
	}
}

void	swap_ops(t_stack **a, t_stack **b, int mode)
{
	if (mode == 1)
	{
		ft_swap(a);
		write(1, "sa\n", 3);
	}
	else if (mode == 2)
	{
		ft_swap(b);
		write(1, "sb\n", 3);
	}
	else if (mode == 3)
	{
		ft_swap(a);
		ft_swap(b);
		write(1, "ss\n", 3);
	}
}

void	ft_rotate(t_stack **lst, int rev)
{
	t_stack	*last;
	t_stack	*tmp;

	if (ft_stack_size(*lst) >= 2)
	{
		if (rev == 0)
		{
			last = ft_last(*lst)->next;
			tmp = *lst;
			(*lst) = (*lst)->next;
			tmp->next = last->next;
			last->next = tmp;
		}
		else if (rev == 1)
		{
			tmp = ft_last(*lst);
			last = tmp->next;
			tmp->next = 0;
			last->next = (*lst);
			(*lst) = last;
		}
	}
}

void	rotate_ops(t_stack **a, t_stack **b, int mode, int rev)
{
	if (mode == 1)
	{
		ft_rotate(a, rev);
		if (rev == 1)
			write(1, "rra\n", 4);
		else
			write(1, "ra\n", 3);
	}
	else if (mode == 2)
	{
		ft_rotate(b, rev);
		if (rev == 1)
			write(1, "rrb\n", 4);
		else
			write(1, "rb\n", 3);
	}
	else if (mode == 3)
	{
		ft_rotate(a, rev);
		ft_rotate(b, rev);
		if (rev == 1)
			write(1, "rrr\n", 4);
		else
			write(1, "rr\n", 3);
	}
}

void	push(t_stack **a, t_stack **b, int mode)
{
	t_stack	*tmp;

	if (mode == 1)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		add_at_front(a, tmp);
		write(1, "pa\n", 3);
	}
	else
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		add_at_front(b, tmp);
		write(1, "pb\n", 3);
	}
}
