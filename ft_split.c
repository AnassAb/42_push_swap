/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:59:30 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/28 12:15:19 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(char *s, int i)
{
	if (ft_isdigit(s[i]) || s[i] == 32)
		return (1);
	if ((i == 0 || s[i - 1] == 32) && (s[i] == '-' || s[i] == '+')
		&& ft_isdigit(s[i + 1]))
		return (1);
	return (0);
}

int	skip_digits(char *s, int i, t_stack **a)
{
	if ((s[i] == '-' || s[i] == '+'))
		i++;
	while (s[i])
	{
		if (!is_valid(s, i))
			ft_error(a);
		else if (ft_isdigit(s[i]))
			i++;
		else
			break ;
	}
	return (i);
}

void	ft_split(char *s, t_stack **a)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!is_valid(s, i))
			ft_error(a);
		if (s[i] == '-' || s[i] == '+')
		{
			add_at_end(a, new_node(ft_atoi(s + i, a)));
			i = skip_digits(s, i, a) - 1;
		}
		else if (ft_isdigit(s[i]))
		{
			add_at_end(a, new_node(ft_atoi(s + i, a)));
			i = skip_digits(s, i, a) - 1;
		}
		i++;
	}
}
