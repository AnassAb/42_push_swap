/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:06:47 by anass             #+#    #+#             */
/*   Updated: 2024/02/29 16:04:12 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	}
	else if (mode == 2)
	{
		ft_swap(b);
	}
	else if (mode == 3)
	{
		ft_swap(a);
		ft_swap(b);
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
	}
	else if (mode == 2)
	{
		ft_rotate(b, rev);
	}
	else if (mode == 3)
	{
		ft_rotate(a, rev);
		ft_rotate(b, rev);
	}
}

void	push(t_stack **a, t_stack **b, int mode)
{
	t_stack	*tmp;

	if (mode == 1 && *b != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		add_at_front(a, tmp);
	}
	else if (mode == 2)
	{
		if (*a != NULL)
		{
			tmp = *a;
			*a = (*a)->next;
			tmp->next = NULL;
			add_at_front(b, tmp);
		}
	}
}
