/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:10:21 by yejeon            #+#    #+#             */
/*   Updated: 2021/03/25 08:56:06 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_info_w_l(va_list *ap, t_info *info, char *p)
{
	int		value;

	if (*p == '*')
	{
		value = va_arg(*ap, int);
		if (value < 0)
		{
			if (!info->dot)
			{
				value *= -1;
				info->flag = '-';
			}
		}
		p++;
	}
	else
	{
		value = ft_atoi(p);
		while (ft_isdigit(*p))
			p++;
	}
	if (info->dot)
		info->length = value;
	else
		info->width = value;
	return (p);
}

static char *set_info(va_list *ap, t_info *info, char *p)
{
	ft_memset(info, 0, sizeof(t_info));
	while (is_flag(*p))
	{
		if (info->flag != '-')
			info->flag = *p;
		p++;
	}
	p = set_info_w_l(ap, info, p);
	if (*p == '.')
	{
		info->dot = *p++;
		p = set_info_w_l(ap, info, p);
	}
	info->type = *p++;
	return (p);
}

int	print_value(va_list *ap, t_info *info)
{
	int		len;

	len = 0;
	if (info->type == '%')
		len = print_char(info, '%');
	else if (info->type == 'c')
		len = print_char(info, va_arg(*ap, int));
	else if (info->type == 's')
		len = print_str(info, va_arg(*ap, char*));
	else if (info->type == 'p')
		len = print_pointer(info, va_arg(*ap, char*));
	else if (info->type == 'i' || info->type == 'd' || \
		info->type == 'u' || info->type == 'x' || info->type == 'X')
		len = print_int(info, va_arg(*ap, int));
	return (len);
}

static int	parse_format(va_list *ap, char *p)
{
	t_info	info;
	int		len;

	len = 0;
	while (*p)
	{
		if (*p == '%')
		{
			p = set_info(ap, &info, ++p);
			len += print_value(ap, &info);
		}
		else
		{
			ft_putchar_fd(*p, 1);
			len++;
			p++;
		}
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = parse_format(&ap, (char*)format);	
	va_end(ap);
	return (len);
}
