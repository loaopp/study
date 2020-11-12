/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:06:02 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/12 22:57:50 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;
	size_t	i;

	len = ft_strlen(s) + 1;
	p = (char*)malloc(len * sizeof(char));
	if (0 == p)
		return (0);
	i = 0;
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}
