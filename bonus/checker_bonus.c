/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:42:35 by anass             #+#    #+#             */
/*   Updated: 2024/02/28 10:39:19 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	print_stack(t_stack *a, char *name)
{
	printf("%s: ", name);
	while (a)
	{
		printf("%d\t", a->num);
		a = a->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*instruction;

	a = NULL;
	b = NULL;
	get_numbers(ac, av, &a);
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
