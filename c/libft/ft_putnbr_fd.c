/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:15:23 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/12 07:20:16 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_my_itoa(char *buf, int n)
{
	int		sign;
	int		i;

	i = 0;
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	while (n)
	{
		buf[i++] = (n % 10) * sign + '0';
		n = n / 10;
	}
	if (sign < 0)
		buf[i++] = '-';
	if (0 == i)
		buf[i++] = '0';
	buf[i] = 0;
	ft_strrev_bonus(buf);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	buf[12];

	if (fd <= 0)
		return ;
	ft_my_itoa(buf, n);
	write(fd, buf, ft_strlen(buf));
}
