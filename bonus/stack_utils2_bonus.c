/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:09:57 by anass             #+#    #+#             */
/*   Updated: 2024/02/28 10:43:16 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	while (a && a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}
