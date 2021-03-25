/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 07:25:27 by yejeon            #+#    #+#             */
/*   Updated: 2021/03/25 08:27:32 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pointer_null(t_info *info)
{
	int		len;

	len = 0;
	if (info->flag != '-')
		len += print_char_while(' ', info->width - 2 - info->length);
	len += write(1, &"0x", 2);
	len += print_char_while('0', info->length);
	if (info->flag == '-')
		len += print_char_while(' ', info->width - 2 - info->length);
	return (len);
}

static int	print_pointer_not_null(t_info *info, char *buf)
{
	int		len;
	int		x;
	
	len = 0;
	x = ft_strlen(buf);
	if (info->flag != '-' && info->dot)
		len += print_char_while(' ', info->width - 2 - \
			((info->length > x) ? info->length : x));
	else if (info->flag == 0)
		len += print_char_while(' ', info->width - 2 - x);
	len += write(1, &"0x", 2);
	if (info->flag == '0' && info->dot == 0)
		len += print_char_while('0', info->width - 2 - x);
	len += print_char_while('0', info->length - x);
	len += write(1, buf, x);
	if (info->flag == '-')
		len += print_char_while(' ', info->width - len);
	return (len);
}

int		print_pointer(t_info *info, char *p)
{
	char	*buf;
	int		len;

	len = 0;
	if (info->dot && p == NULL)
		len = print_pointer_null(info);
	else
	{
		buf = get_str_by_info(info, (size_t)p);
		len = print_pointer_not_null(info, buf);
		free(buf);
	}
	return (len);
}
