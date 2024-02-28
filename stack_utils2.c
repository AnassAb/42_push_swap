/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:03:30 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/17 12:27:58 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_last(t_stack *lst)
{
	t_stack	*ptr;

	ptr = NULL;
	if (lst == NULL)
		return (0);
	ptr = lst;
	while (ptr->next->next)
		ptr = ptr->next;
	return (ptr);
}

int	stack_is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

int	get_nearest(int *arr_a, int n, int nbr)
{
	int		i;
	long	diff;
	long	cur_diff;
	int		pos_near;

	i = 0;
	pos_near = -1;
	while (i < n)
	{
		cur_diff = ft_abs(nbr - (long)arr_a[i]);
		if (pos_near == -1 || cur_diff < diff)
		{
			pos_near = i;
			diff = cur_diff;
		}
		i++;
	}
	return (pos_near);
}

int	get_target_pos(t_stack *a, int nbr)
{
	int	nearest;
	int	*arr_a;
	int	size_a;

	size_a = ft_stack_size(a);
	arr_a = stack_to_arr(a, size_a);
	nearest = get_nearest(arr_a, size_a, nbr);
	if (arr_a[nearest] < nbr)
		nearest++;
	free(arr_a);
	return (nearest);
}

int	get_current_pos(t_stack *b, int nbr)
{
	int	i;

	i = 0;
	while (b)
	{
		if (b->num == nbr)
			return (i);
		i++;
		b = b->next;
	}
	return (i);
}
