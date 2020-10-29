/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:06:02 by yejeon            #+#    #+#             */
/*   Updated: 2020/10/29 12:27:42 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;
	size_t	i;

	len = 0;
	while (*(s1 + len))
		len++;
	len++;
	p = (char*)malloc(len * sizeof(char));
	i = 0;
	while (i < len)
	{
		*(p + i) = *(s1 + i);
		i++;
	}
	return (p);
}
