/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:57:50 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/28 12:57:22 by anass            ###   ########.fr       */
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

int	check_string(char *s)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (s[i])
	{
		if (!(ft_isdigit(s[i]) || s[i] == 32 || s[i] == '-' || s[i] == '+'))
			return (0);
		if (ft_isdigit(s[i]))
			d = 1;
		i++;
	}
	return (d);
}

int	nums_are_valid(char *s)
{
	int	i;

	i = 0;
	if (check_string(s) == 0)
		return (0);
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
	if (ft_isdigit(s[i]))
		return (2);
	if ((s[i] == '-' || s[i] == '+') && ft_isdigit(s[i + 1]))
		return (2);
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
	int	nums_v;

	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			nums_v = nums_are_valid(av[i]);
			if (nums_v == 2)
				ft_split(av[i], a);
			else if (nums_v == 1)
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
