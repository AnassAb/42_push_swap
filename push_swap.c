/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:05:50 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/28 12:26:02 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	get_numbers(ac, av, &a);
	if (ft_stack_size(a) == 0 || stack_is_sorted(a))
	{
		ft_clear_lst(&a);
		exit(0);
	}
	size = ft_stack_size(a);
	sort_stack(&a, &b, size);
	ft_clear_lst(&a);
	ft_clear_lst(&b);
	return (0);
}
