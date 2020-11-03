/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:39:45 by yejeon            #+#    #+#             */
/*   Updated: 2020/10/29 12:27:26 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	i;
	size_t	total;

	total = nmemb * size;
	p = malloc(total);
	if (p)
	{
		i = 0;
		while (i < total)
		{
			*((char*)p + i) = 0;
			i++;
		}
	}
	return (p);
}
