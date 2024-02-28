/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:02:18 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/16 15:58:59 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int num)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->num = num;
	node->next = NULL;
	return (node);
}

void	ft_clear_lst(t_stack **lst)
{
	t_stack	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = *lst;
			(*lst) = (*lst)->next;
			free(tmp);
		}
	}
}

void	add_at_end(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst)
	{
		if (!new)
		{
			ft_clear_lst(lst);
			write(2, "Error\n", 6);
			exit(1);
		}
		last = *lst;
		if (*lst != NULL)
		{
			while (last->next)
				last = last->next;
			last->next = new;
		}
		else
		{
			*lst = new;
		}
	}
}

void	add_at_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		if (*lst)
		{
			new->next = *lst;
			*lst = new;
		}
		else
			*lst = new;
	}
}

int	ft_stack_size(t_stack *lst)
{
	int		count;
	t_stack	*ptr;

	if (!lst)
		return (0);
	count = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
