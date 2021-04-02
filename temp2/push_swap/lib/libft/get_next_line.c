/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:39:51 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/21 01:02:08 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_buffer(char **sbuffer)
{
	if (sbuffer && *sbuffer)
	{
		free(*sbuffer);
		*sbuffer = NULL;
	}
}

int		print_buffer(char **sbuffer, char **line, char *tmp)
{
	char	*memory;

	free_buffer(line);
	*line = ft_strsub2(*sbuffer, 0, ft_strlen2(*sbuffer) - ft_strlen2(tmp));
	memory = *sbuffer;
	*sbuffer = ft_strsub2(*sbuffer, ft_strlen2(*line) + 1, ft_strlen2(*sbuffer));
	free_buffer(&memory);
	return (1);
}

int		refill_buff(int fd, char **sbuffer, char *tmp, char **line)
{
	char	*free_buf;
	int		rs;
	char	*tmp2;

	while ((rs = read(fd, tmp, BUFFER_SIZE)) != -1)
	{
		if (rs == 0)
			break ;
		tmp[rs] = 0x00;
		free_buf = *sbuffer;
		*sbuffer = ft_strjoin2(*sbuffer, (const char *)tmp);
		free_buffer(&free_buf);
		if ((tmp2 = ft_strchr2((const char *)(*sbuffer), '\n')))
		{
			return (print_buffer(sbuffer, line, tmp2));
		}
	}
	return (rs);
}

int		get_next_line(int fd, char **line)
{
	static char	*sbuffer;
	int			rs;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_strdup2("");
	if ((tmp = ft_strchr2((const char *)sbuffer, '\n')))
	{
		return (print_buffer(&sbuffer, line, tmp));
	}
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	rs = refill_buff(fd, &sbuffer, tmp, line);
	free(tmp);
	if (rs != 0)
		return (rs);
	if (ft_strlen2((const char *)sbuffer) > 0)
	{
		free_buffer(line);
		*line = ft_strdup2((const char*)sbuffer);
		free_buffer(&sbuffer);
	}
	return (0);
}
