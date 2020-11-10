/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:26:31 by droslyn           #+#    #+#             */
/*   Updated: 2020/11/10 22:54:45 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				memsearch(char *mem, char c)
{
	size_t		i;

	i = 0;
	while (mem[i] != '\0')
	{
		if (mem[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_free(char *mem)
{
	free(mem);
	mem = NULL;
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	static char *ptr_line;
	int			n;
	int			pos;
	char		*buf;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	n = 0;
	pos = -1;
	if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while (pos == -1)
	{
		if ((n = read(0, buf, BUFFER_SIZE)) == -1)
			return (ft_free(buf));
		buf[n] = '\0';
		pos = ft_memsearch(buf, '\n');
		ptr_line = ft_strjoin(ptr_line, buf, pos);
	}
}
