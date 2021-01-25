/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:35:49 by yejeon            #+#    #+#             */
/*   Updated: 2021/01/25 16:38:34 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t	i;

	if (dest == 0 || src == 0)
		return (0);
	d = (unsigned char*) dest;
	s = (unsigned char*) src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s) + 1;
	p = (char*)malloc(sizeof(char) * len);
	if (!p)
		return (0);
	ft_memcpy(p, s, len);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*p;

	if (0 == s1 && 0 == s2)
		return (0);
	else if (0 == s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && 0 == s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = (char*)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!p)
		return (0);
	ft_memcpy(p, s1, len_s1);
	ft_memcpy(p + len_s1, s2, len_s2 + 1);
	return (p);
}

char	*ft_strchr(const char *s, unsigned char c)
{
	if (0 == s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (0 == c)
		return ((char*)s);
	return (0);
}

