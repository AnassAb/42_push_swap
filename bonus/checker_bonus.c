/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:42:35 by anass             #+#    #+#             */
/*   Updated: 2024/02/28 14:34:29 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*instruction;

	a = NULL;
	b = NULL;
	get_numbers(ac, av, &a);
	if (ft_stack_size(a) == 0)
		exit(0);
	instruction = get_next_line(0);
	while (instruction)
	{
		exec_instruction(instruction, &a, &b);
		free(instruction);
		instruction = get_next_line(0);
	}
	free(instruction);
	if (ft_stack_size(b) == 0 && stack_is_sorted(a))
		write(1, "\nOK\n", 4);
	else
		write(1, "\nKO\n", 4);
	ft_clear_lst(&a);
	ft_clear_lst(&b);
	return (0);
}
