/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:11:53 by yejeon            #+#    #+#             */
/*   Updated: 2021/03/25 11:12:01 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	recursive_ltoa(char *buf, unsigned int u)
{
	int		i;

	if (u == 0)
		return (0);
	i = recursive_ltoa(buf, u / 10);
	buf[i] = (u % 10) + '0';
	return (i + 1);
}

char				*ft_ltoa(unsigned int u)
{
	char	buf[11];

	ft_bzero(buf, sizeof(buf));
	if (u == 0)
		buf[0] = '0';
	recursive_ltoa(buf, u);
	return (ft_strdup(buf));
}
