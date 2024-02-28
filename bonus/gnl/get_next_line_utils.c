/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:23:17 by anass             #+#    #+#             */
/*   Updated: 2024/02/23 10:47:41 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_lens(char *s, int mode)
{
	int	i;

	i = 0;
	if (mode == 1)
	{
		while (s && s[i])
			i++;
	}
	else
	{
		while (s && s[i] && s[i] != '\n')
			i++;
		if (!s || s[i] == '\0')
			return (-1);
	}
	return (i);
}

char	*ft_substr(char *s, int start, int end)
{
	int		i;
	char	*res;

	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (0);
	i = 0;
	while (start < end)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	ssize_t	i;
	ssize_t	len1;
	ssize_t	len2;
	char	*res;

	len1 = ft_lens(s1, 1);
	len2 = ft_lens(s2, 1);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	while ((i - len1) < len2)
	{
		res[i] = s2[i - len1];
		i++;
	}
	res[i] = '\0';
	return (res);
}
