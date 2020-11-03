/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:28:12 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/03 22:28:12 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_count(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			cnt++;
		s++;
	}
	return (cnt + 1);
}

static void	ft_free(void **list)
{
	size_t	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

char		**ft_split(char const *s, char c)
{
	char	**list;
	char	*p;
	char	*pos;
	size_t	i;

	list = (char**)ft_calloc(ft_get_count(s, c), sizeof(char*));
	if (list == 0)
		return (0);
	i = 0;
	p = (char*)s;
	pos = p;
	while (0 != (p = ft_strchr(p, c)))
	{
		list[i] = ft_substr(s, pos - s, p - pos);
		if (list[i] == 0)
		{
			ft_free((void**)list);
			return (0);
		}
		i++;
		pos = p + 1;
		p++;
	}
	list[i] = ft_substr(s, pos - s, -1);
	return (list);
}
