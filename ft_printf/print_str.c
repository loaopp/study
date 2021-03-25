/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 00:47:46 by yejeon            #+#    #+#             */
/*   Updated: 2021/03/25 12:37:06 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(t_info *info, int ch)
{
	int		len;

	len = 0;
	if (info->flag != '-')
	{
		if (info->flag == '0')
			len += print_char_while('0', info->width - 1);
		else
			len += print_char_while(' ', info->width - 1);
	}
	len += write(1, &ch, 1);
	if (info->flag == '-')
		len += print_char_while(' ', info->width - 1);
	return (len);
}

int		print_str(t_info *info, char *s)
{
	int		x;
	int		len;

	len = 0;
	if (s == NULL)
		s = "(null)";
	x = ft_strlen(s);
	if (info->length < 0)
		info->dot = 0;
	if (info->dot && info->length < x)
		x = info->length;
	if (info->flag == '0')
		len += print_char_while('0', info->width - x);
	else if (info->flag == 0)
		len += print_char_while(' ', info->width - x);
	len += write(1, s, x);
	if (info->flag == '-')
		len += print_char_while(' ', info->width - x);
	return (len);
}
