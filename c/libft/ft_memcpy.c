/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:30:17 by yejeon            #+#    #+#             */
/*   Updated: 2020/10/21 18:30:17 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cpy_head(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char*)dest + i) = *((char*)src + i);
		i++;
	}
}

void	ft_cpy_tail(void *dest, const void *src, size_t n)
{
	while (n)
	{
		*((char*)dest + n - 1) = *((char*)src + n - 1);
		n--;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (dest < src)
		ft_cpy_head(dest, src, n);
	else
		ft_cpy_tail(dest, src, n);
	return (dest);
}
