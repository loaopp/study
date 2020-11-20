/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 08:25:23 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/20 12:42:35 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
int		get_next_line(int fd, char **line)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		size;
	char		*pos;
	char		*temp;

	if (fd < 0 || NULL == line || BUFFER_SIZE < 1)
		return (-1);
	while (0 < (size = read(fd, buf, BUFFER_SIZE)))
	{
		buf[size] = 0;
		if (str)
		{
		temp = str;
		str = ft_strjoin(str, buf);
		free(temp);
		}
		else
		{
			str = ft_strdup(buf);
		}
		pos = ft_strchr(buf, '\n');
		if (pos)
			break ;
	}
	pos = ft_strchr(str, '\n');
	if (pos)
	{
		*pos = 0;
		temp = str;
		*line = ft_strdup(str);
		str = ft_strdup(pos + 1);
		free(temp);
		return (1);
	}
	return (0);
}


int main()
{
	int	fd;
	char	*line;

	fd = open("./test1.txt", O_RDONLY);
	while (0 < get_next_line(fd, &line))
	{
		puts(line);
		puts("----------------------");
		free(line);
	}
	close(fd);
	return (0);
}
