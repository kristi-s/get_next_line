/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:26:31 by droslyn           #+#    #+#             */
/*   Updated: 2020/11/13 15:00:29 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char			*ft_get_line(char *str)
{
	size_t		len;
	char		*new_str;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (!(new_str = malloc((len + 1) * sizeof(char))))
		return (0);
	new_str[len] = '\0';
	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
	{
		new_str[len] = str[len];
		len++;
	}
/*	if (str[len] == '\0')
	{
		printf("clean remem\n"); //del -----------------!!!!!!!!!
		ft_free(str, 0);
	}*/
	return (new_str);
}

char			*ft_get_remem(char *str)
{
	size_t		pref;
	size_t		len;
	char		*new_str;

/*	if (!str)
	{
		printf("remem null, exit (ft_get_remem)\n"); //del -----------------!!!!!!!!!
		return (0);
	}*/
	pref = 0;
	len = 0;
	while (str[pref] != '\n' && str[pref] != '\0')
		pref++;
	if (str[pref] != '\0')
		pref++;
	else
	{
//		printf("ft_get_remem NULL\n");/// del--------------!!!!!!!!!!
		ft_free(str, 0);
		return (0);
	}
	while (str[pref + len] != '\0')
		len++;
	if (!(new_str = malloc((len + 1) * sizeof(char))))
		return (0);
	new_str[len] = '\0';
	len = 0;
	while (str[pref + len] != '\0')
	{
		new_str[len] = str[pref + len];
		len++;
	}
	ft_free(str, 0);

//printf("ft_get_remem = %s\n", new_str);/// del--------------!!!!!!!!!!
	return (new_str);
}

int				get_next_line(int fd, char **line)
{
	static char *remem;
	int			n_rd;
	int			pos;
	char		*buf;

//	printf("ft_get_next_line remem = %s     %p\n", remem, remem);/// del--------------!!!!!!!!!!
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	n_rd = 1;
	if ((pos = ft_memsearch(remem)) == 0)
	{
//		printf("ft_get_next_line pos = %d\n", pos);/// del--------------!!!!!!!!!!	
		if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
			return (-1);
		while (pos == 0 && n_rd > 0)
		{			
			if ((n_rd = read(fd, buf, BUFFER_SIZE)) == -1)
				return (ft_free(buf, 0));
			buf[n_rd] = '\0';
			pos = ft_memsearch(buf);
			if (!(remem = ft_strjoin(remem, buf)))
				return (ft_free(remem, buf));
		}
		ft_free(buf, 0);
	}
	if (!(*line = ft_get_line(remem)))
		return (ft_free(remem, 0));
	remem = ft_get_remem(remem);
	if (!n_rd && remem)
		n_rd = 1;
	return (n_rd > 0 ? 1 : 0);
}
