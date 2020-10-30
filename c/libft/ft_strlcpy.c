/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:48:32 by yejeon            #+#    #+#             */
/*   Updated: 2020/10/29 11:15:51 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	char	*p;

	p = src;
	if (size)
	{
		while (*src)
		{
			if (--size == 0)
				break ;
			*dest++ = *src++;
		}
		*dest = 0;
	}
	while (*src)
		src++;
	return (src - p);
}
