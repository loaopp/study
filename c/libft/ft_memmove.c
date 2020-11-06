/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:45:02 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/06 21:45:02 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char*)dest;
	p2 = (unsigned char*)src;
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			p1[i] = p2[i];
			i++;
		}
	}
	else
	{
		while (n--)
			p1[n] = p2[n];
	}
	return (dest);
}
