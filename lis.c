/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:09:17 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/16 15:01:08 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_seq_lens(int *arr, int n)
{
	int	i;
	int	j;
	int	comb;
	int	*sq_lens;

	sq_lens = (int *)malloc(sizeof(int) * n);
	if (!sq_lens)
		return (0);
	i = 0;
	while (i < n)
	{
		sq_lens[i] = 1;
		j = 0;
		comb = -1;
		while (j < i)
		{
			if (arr[j] < arr[i] && (comb == -1 || sq_lens[j] > sq_lens[comb]))
				comb = j;
			j++;
		}
		if (comb > -1)
			sq_lens[i] += sq_lens[comb];
		i++;
	}
	return (sq_lens);
}

int	get_len(int *lens, int n)
{
	int	i;
	int	max;

	i = 0;
	max = lens[0];
	while (i < n)
	{
		if (lens[i] > max)
			max = lens[i];
		i++;
	}
	return (max);
}

int	get_ind(int *lens, int n)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < n)
	{
		if (lens[i] > lens[j])
			j = i;
		i++;
	}
	return (j);
}

int	get_prev(int *arr, int *lens, int ind)
{
	int	new_ind;

	new_ind = 0;
	while (new_ind < ind)
	{
		if (arr[new_ind] < arr[ind] && (lens[ind] - lens[new_ind]) == 1)
			return (new_ind);
		new_ind++;
	}
	return (new_ind);
}

int	*ft_lis(t_stack *a, int n, int *lis_len)
{
	int	i;
	int	ind;
	int	*lis;
	int	*arr;
	int	*sq_len;

	arr = stack_to_arr(a, n);
	sq_len = get_seq_lens(arr, n);
	*lis_len = get_len(sq_len, n);
	ind = get_ind(sq_len, n);
	lis = (int *)malloc(sizeof(int) * ((*lis_len) + 1));
	if (!lis || !arr || !sq_len)
		return (free(arr), free(sq_len), free(lis), NULL);
	i = (*lis_len) - 1;
	while (i >= 0)
	{
		lis[i] = arr[ind];
		ind = get_prev(arr, sq_len, ind);
		i--;
	}
	free(arr);
	free(sq_len);
	return (lis);
}
