/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:15:23 by yejeon            #+#    #+#             */
/*   Updated: 2020/11/11 05:56:19 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*nbr;

	if (fd <= 0)
		return ;
	nbr = ft_itoa(n);
	if (0 == nbr)
		return ;
	write(fd, nbr, ft_strlen(nbr));
	free(nbr);
}
