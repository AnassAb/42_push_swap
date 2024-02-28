/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:59:34 by aabidar           #+#    #+#             */
/*   Updated: 2024/02/28 11:19:15 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == 32)
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	atoi_sign_check(char *s, int *i, int *sg, int *len)
{
	if ((s[(*i)] == '-' || s[(*i)] == '+'))
	{
		if (s[(*i)] == '-')
			(*sg) *= -1;
		(*i)++;
		(*len)++;
	}
}

int	ft_atoi(char *s, t_stack **a)
{
	int		i;
	int		sg;
	long	res;
	int		len;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	sg = 1;
	len = 0;
	atoi_sign_check(s, &i, &sg, &len);
	res = 0;
	while (s[i] && ft_isdigit(s[i]))
	{
		res = res * 10 + (s[i] - '0');
		i++;
		len++;
	}
	res *= sg;
	if (res > 2147483647 || res < -2147483648 || len > 11)
		ft_error(a);
	return (res);
}
