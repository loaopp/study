/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 21:10:35 by yejeon            #+#    #+#             */
/*   Updated: 2020/10/21 21:10:35 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t	i;

	p = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (*(p + i) == c)
			break;
		i++;
	}
	if (i == n)
		return (0);
	else
		return (p + i);
}
