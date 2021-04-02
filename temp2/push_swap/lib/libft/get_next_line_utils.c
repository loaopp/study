/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:43:22 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/21 01:08:36 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strchr2(const char *str, int n)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == n)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}

char		*ft_strdup2(const char *src)
{
	int		i;
	int		count;
	char	*ret;

	i = 0;
	count = 0;
	while (src[i])
	{
		i++;
		count++;
	}
	ret = (char *)malloc((count + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (i < count)
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = 0x00;
	return (ret);
}

char		*ft_strsub2(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if ((!s) || (start > ft_strlen2(s)))
		return (NULL);
	if (!(sub = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while ((i < len) && (s[start] != 0x00))
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = 0x00;
	return (sub);
}

size_t		ft_strlen2(const char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char		*ft_strjoin2(const char *s1, const char *s2)
{
	char	*joined;
	size_t	i;
	size_t	k;
	size_t	y;
	size_t	z;

	i = 0;
	k = 0;
	y = ft_strlen2(s1);
	z = ft_strlen2(s2);
	if (!(joined = (char *)malloc((y + z + 1) * sizeof(char))))
		return (NULL);
	while (i < y)
	{
		joined[i] = s1[i];
		i++;
	}
	while (i < y + z)
	{
		joined[i] = s2[k];
		i++;
		k++;
	}
	joined[i] = 0x00;
	return (joined);
}
