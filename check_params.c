/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:57:50 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/28 10:55:11 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack **a)
{
	if (ft_stack_size(*a) != 0)
		ft_clear_lst(a);
	write(2, "Error\n", 6);
	exit(1);
}

int	num_is_valid(char *s)
{
	int	i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if ((s[i] == '-' || s[i] == '+') && ft_isdigit(s[i + 1]))
		i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

void	check_dup(t_stack **a)
{
	t_stack	*curr;
	t_stack	*next;

	curr = (*a);
	next = (*a)->next;
	while (curr->next)
	{
		while (next)
		{
			if (curr->num == next->num)
				ft_error(a);
			next = next->next;
		}
		curr = curr->next;
		next = curr->next;
	}
}

void	get_numbers(int ac, char **av, t_stack **a)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		*a = ft_split(av[1]);
		if (*a == NULL)
			ft_error(a);
	}
	else if (ac > 2)
	{
		i = 1;
		while (i < ac)
		{
			if (num_is_valid(av[i]))
				add_at_end(a, new_node(ft_atoi(av[i], a)));
			else
				ft_error(a);
			i++;
		}
	}
	else
		exit(0);
	check_dup(a);
}
