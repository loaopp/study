/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 08:59:35 by yejeon            #+#    #+#             */
/*   Updated: 2021/03/25 00:54:23 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	recursive_hex(size_t n, char *buf, int upper)
{
	const char	*base = "0123456789abcdef";
	const char	*base2 = "0123456789ABCDEF";
	size_t		i;

	if (n >> 4)
		i = recursive_hex(n >> 4, buf, upper);
	else
		i = 0;
	if (upper)
		buf[i] = base2[n & 0x0f];
	else
		buf[i] = base[n & 0x0f];
	buf[i + 1] = 0;
	return (i + 1);
}

char			*ft_hex_bonus(size_t n, int head, int upper)
{
	char	buf[19];

	if (head)
	{
		ft_memcpy(buf, "0x", 2);
		recursive_hex(n, &buf[2], upper);
	}
	else
		recursive_hex(n, buf, upper);
	return (ft_strdup(buf));
}
