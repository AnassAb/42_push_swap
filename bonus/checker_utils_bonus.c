/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:52:49 by anass             #+#    #+#             */
/*   Updated: 2024/02/18 14:04:33 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_free(t_stack **a, t_stack **b)
{
	write(2, "Error\n", 6);
	ft_clear_lst(a);
	ft_clear_lst(b);
	exit(1);
}

void	exec_instruction_helper(char *inst, t_stack **a, t_stack **b)
{
	if ((inst[2] == '\n' || inst[2] == '\0'))
	{
		if (inst[1] == 'a')
			return (rotate_ops(a, b, 1, 0));
		if (inst[1] == 'b')
			return (rotate_ops(a, b, 2, 0));
		if (inst[1] == 'r')
			return (rotate_ops(a, b, 3, 0));
	}
	if (inst[1] == 'r' && (inst[3] == '\n' || inst[3] == '\0'))
	{
		if (inst[2] == 'a')
			return (rotate_ops(a, b, 1, 1));
		if (inst[2] == 'b')
			return (rotate_ops(a, b, 2, 1));
		if (inst[2] == 'r')
			return (rotate_ops(a, b, 3, 1));
	}
	ft_free(a, b);
}

void	exec_instruction(char *inst, t_stack **a, t_stack **b)
{
	if (inst[0] == 'p' && (inst[2] == '\n' || inst[2] == '\0'))
	{
		if (inst[1] == 'a')
			return (push(a, b, 1));
		if (inst[1] == 'b')
			return (push(a, b, 2));
	}
	if (inst[0] == 'r')
		return (exec_instruction_helper(inst, a, b));
	if (inst[0] == 's' && (inst[2] == '\n' || inst[2] == '\0'))
	{
		if (inst[1] == 'a')
			return (swap_ops(a, b, 1));
		if (inst[1] == 'b')
			return (swap_ops(a, b, 2));
		if (inst[1] == 's')
			return (swap_ops(a, b, 3));
	}
	ft_free(a, b);
}
