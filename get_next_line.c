/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:26:31 by droslyn           #+#    #+#             */
/*   Updated: 2020/11/11 20:10:51 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_get_line(char *str)
{
	size_t		len;
	char		*new_str;

	len = 0;
	while (str[len] != '\n' && *str[len] != '\0')
		len++;
	if (!(new_str = malloc((len + 1) * sizeof(char))))
		return (0);
	new_str[len] = '\0';
	len = 0;
	while (str[len] != '\n' && *str[len] != '\0')
	{
		new_str[len] = str[len];
		len++;
	}
	return (new_str);
}

int				get_next_line(int fd, char **line)
{
	static char *remem;
	int			n_rd;
	int			pos;
	char		*buf;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	n_rd = 1;
	if ((pos = ft_memsearch(remem)) == -1)
	{
		if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
			return (-1);
		while (pos == -1)
		{
			if ((n_rd = read(0, buf, BUFFER_SIZE)) == -1)
				return (ft_free(buf));
			buf[n_rd] = '\0';
			pos = ft_memsearch(buf);
			remem = ft_strjoin(remem, buf);
		}
		ft_free(buf);
	}
	*line = ft_get_line(remem);
	remem = get_remem(remem);
	return (n_rd > 0 ? 1 : 0);
}
