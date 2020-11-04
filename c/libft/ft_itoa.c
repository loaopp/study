/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:37:31 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/03 23:37:31 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	temp[12];
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (n < 0)
		sign = -1;
	while (n)
	{
		temp[i++] = (n % 10) * sign + '0';
		n = n / 10;
	}
	if (sign < 0)
		temp[i++] = '-';
	temp[i] = 0;
	return (ft_strdup(ft_strrev(temp)));
}
