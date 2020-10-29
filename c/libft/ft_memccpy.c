/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:39:11 by yejeon            #+#    #+#             */
/*   Updated: 2020/10/29 11:14:22 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_cpy_head(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	void	*p;

	i = 0;
	p = 0;
	while (i < n)
	{
		*((char*)dest + i) = *((char*)src + i);
		if (*((char*)src + i) == c)
		{
			p = dest + i + 1;
			break ;
		}
		i++;
	}
	return (p);
}

void	*ft_cpy_tail(void *dest, const void *src, int c, size_t n)
{
	while (n)
	{
		*((char*)dest + n - 1) = *((char*)src + n - 1);
		n--;
	}
}

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	if (dest < src)
		return (t_cpy_head(dest, src, c, n));
	else
		return (ft_cpy_tail(dest, src, c, n));
}
