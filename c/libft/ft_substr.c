/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:29:08 by yejeon            #+#    #+#             */
/*   Updated: 2020/10/29 12:42:40 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	size;

	if (s == 0)
		return (0);
	len_s = ft_strlen(s);
	if (len_s - start < len)
		size = len_s - start;
	else
		size = len;
	return ((char*)ft_memcpy(ft_calloc(sizeof(char), size + 1), s + start, size));
}
