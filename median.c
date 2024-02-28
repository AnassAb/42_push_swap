/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:53:24 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/17 12:20:31 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_arr(t_stack *a, int size)
{
	int	i;
	int	*res;

	res = (int *)malloc(size * sizeof(int));
	if (!res)
		return (0);
	i = 0;
	while (a)
	{
		res[i] = a->num;
		a = a->next;
		i++;
	}
	return (res);
}

void	count_upper_lower(t_stack *a, int nbr, int *lower, int *upper)
{
	while (a)
	{
		if (a->num < nbr)
			(*lower)++;
		if (a->num > nbr)
			(*upper)++;
		a = a->next;
	}
}

int	get_mdn(t_stack *a, int size_a)
{
	t_stack	*first;
	int		lower;
	int		upper;

	first = a;
	while (a)
	{
		lower = 0;
		upper = 0;
		count_upper_lower(first, a->num, &lower, &upper);
		if ((size_a % 2 == 0) && abs(lower - upper) == 1)
			break ;
		if ((size_a % 2 != 0) && abs(lower - upper) == 0)
			break ;
		a = a->next;
	}
	return (a->num);
}

void	ft_free(t_stack **a, t_stack **b, int *arr)
{
	write(2, "Error\n", 6);
	ft_clear_lst(a);
	ft_clear_lst(b);
	free(arr);
	exit(1);
}

long	ft_abs(long n)
{
	if (n > 0)
		return (n);
	return (n * -1);
}
