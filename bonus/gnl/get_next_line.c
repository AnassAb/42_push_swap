/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anass <anass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:37:53 by anass             #+#    #+#             */
/*   Updated: 2024/02/23 11:54:11 by anass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readfile(int fd, char *s_buff)
{
	char	*buffer;
	char	*tmp;
	ssize_t	byte_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	byte_read = 1;
	while (byte_read > 0 && ft_lens(s_buff, 2) == -1)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), free(s_buff), NULL);
		buffer[byte_read] = '\0';
		tmp = s_buff;
		s_buff = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	return (s_buff);
}

char	*get_next_line_helper(char **s_buff, ssize_t ind, ssize_t len)
{
	char	*line;
	char	*tmp;

	if (ind != -1)
	{
		line = ft_substr(*s_buff, 0, ind + 1);
		tmp = *s_buff;
		*s_buff = ft_substr(tmp, ind + 1, len);
		free(tmp);
	}
	else
	{
		if (len != 0)
			line = ft_substr(*s_buff, 0, len);
		else
			line = NULL;
		free(*s_buff);
		*s_buff = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s_buff;
	ssize_t		len;
	ssize_t		ind;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	s_buff = ft_readfile(fd, s_buff);
	if (!s_buff)
		return (0);
	len = ft_lens(s_buff, 1);
	ind = ft_lens(s_buff, 2);
	return (get_next_line_helper(&s_buff, ind, len));
}
