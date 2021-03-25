/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:16:14 by yejeon            #+#    #+#             */
/*   Updated: 2021/03/25 12:11:25 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_assistance(t_info *info, char *buf, int x, int minus)
{
	int		len;

	len = 0;
	minus = (buf[0] == '-');
	if (info->dot == 0 && info->flag == '0')
		len += print_char_while('0', info->width - x);
	else if (info->dot)
		len += print_char_while('0', info->length - (x - minus));
	len += write(1, buf + minus, x - minus);
	return (len);
}

int			print_int(t_info *info, int n)
{
	char	*buf;
	int		len;
	int		x;
	int		minus;

	len = 0;
	buf = get_str_by_info(info, n);
	minus = (buf[0] == '-');
	if (info->length < 0)
		info->dot = 0;
	if (n == 0 && info->length == 0 && info->dot)
		buf[0] = 0;
	x = ft_strlen(buf);
	if (info->flag != '-' && ((info->dot && info->flag != '-') || \
		(info->dot == 0 && info->flag != '0')))
		len += print_char_while(' ', info->width - \
			((info->length + minus < x) ? x : info->length + minus));
	len += write(1, &"-", minus);
	len += print_assistance(info, buf, x, minus);
	if (info->flag == '-')
		len += print_char_while(' ', info->width - len);
	free(buf);
	return (len);
}
