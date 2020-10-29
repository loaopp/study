/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:37:42 by yejeon            #+#    #+#             */
/*   Updated: 2020/10/29 11:15:00 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_trim(char *str)
{
	while (*str)
	{
		if (!(*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\r' || *str == '\v' || *str == '\f'))
			return (str);
		str++;
	}
	return (0);
}

int		ft_signs(char **str)
{
	char	*p;
	int		sign;

	sign = 1;
	p = *str;
	while (*p)
	{
		if (*p == '-')
			sign *= -1;
		else if (*p != '+')
		{
			*str = p;
			return (sign);
		}
		p++;
	}
	*str = p;
	return (0);
}

int		ft_get_num(char *str)
{
	int		num;

	num = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
		{
			num *= 10;
			num += *str - '0';
		}
		else
			break ;
		str++;
	}
	return (num);
}

int		ft_atoi(char *str)
{
	int		num;
	int		sign;

	str = ft_trim(str);
	sign = ft_signs(&str);
	num = ft_get_num(str);
	return (num * sign);
}
