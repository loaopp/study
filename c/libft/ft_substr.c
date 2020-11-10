/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:29:08 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/11 07:00:10 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	size;
	void	*p;

	if (s == 0)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	len_s = ft_strlen(s + start);
	if (len_s < len)
		size = len_s;
	else
		size = len;
	p = ft_calloc(size + 1, sizeof(char));
	if (0 == p)
		return (0);
	return ((char*)ft_memcpy(p, s + start, size));
}
