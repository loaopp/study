/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:47:33 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/03 18:47:33 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	char	*start;
	char	*end;

	p = (char*)s1;
	start = 0;
	end = 0;
	while (*p)
	{
		if (0 == ft_strchr(set, *p))
		{
			if (0 == start)
				start = p;
			end = p;
		}
		p++;
	}
	if (0 == start)
		start = (char*)s1;
	if (0 == end)
		end = (char*)s1;
	return (ft_substr(s1, start - s1, end - start));
}
#include <stdio.h>

int	main()
{
	char *set = " ";
	char *p;

	p = ft_strtrim("asd", set);
	printf("%p : '%s'\n", p, p);
	p = ft_strtrim("  asd  ", set);
	printf("%p : '%s'\n", p, p);
	p = ft_strtrim(" asd as ", set);
	printf("%p : '%s'\n", p, p);
	p = ft_strtrim("", set);
	printf("%p : '%s'\n", p, p);
	p = ft_strtrim("   ", set);
	printf("%p : '%s'\n", p, p);
	p = ft_strtrim(0, set);

	return (0);
}
