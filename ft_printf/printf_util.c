/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:59:56 by yejeon            #+#    #+#             */
/*   Updated: 2021/03/25 11:55:28 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	is_type(char ch)
{
	const char	*p = ft_strchr(TYPE, ch);

	return (p ? *p : 0);
}

int		is_flag(char ch)
{
	return (ft_strchr(FLAG, ch) ? 1 : 0);
}

int		print_char_while(char ch, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		ft_putchar_fd(ch, 1);
		j++;
	}
	return (j);
}

char	*get_str_by_info(t_info *info, size_t n)
{
	if (info->type == 'i' || info->type == 'd')
		return (ft_itoa((int)n));
	else if (info->type == 'x')
		return (ft_hex_bonus((unsigned int)n, 0, 0));
	else if (info->type == 'X')
		return (ft_hex_bonus((unsigned int)n, 0, 1));
	else if (info->type == 'u')
		return (ft_ltoa((unsigned int)n));
	else if (info->type == 'p')
		return (ft_hex_bonus((size_t)n, 0, 0));
	return (0);
}

void	print_info(t_info *info)
{
	printf("info->flag : [%c]\n", info->flag);
	printf("info->width : [%d]\n", info->width);
	printf("info->dot : [%c]\n", info->dot);
	printf("info->length : [%d]\n", info->length);
	printf("info->type : [%c]\n", info->type);
}
