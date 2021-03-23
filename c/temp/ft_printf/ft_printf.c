/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:10:21 by yejeon            #+#    #+#             */
/*   Updated: 2021/03/23 09:16:11 by yejeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <stdarg.h>

#define TYPE "cspdiuxX%"
#define FLAG "-+ 0#"

int		ft_isspace_bonus(int c)
{
	return (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r');
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


char	*ft_strchr(const char *s, int c)
{
	if (0 == s)
		return (0);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char*)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char*)s);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	if (0 < fd)
		write(fd, &c, sizeof(char));
}
int		ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
int			ft_atoi(const char *nptr)
{
	int		sign;
	int		num;

	while (*nptr && ft_isspace_bonus(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = -1;
	num = 0;
	while (*nptr && ft_isdigit(*nptr))
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * sign);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char*)b;
	i = 0;
	while (i < len)
		p[i++] = (unsigned char)c;
	return (b);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (0);
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s) + 1;
	p = (char*)malloc(len * sizeof(char));
	if (0 == p)
		return (0);
	ft_memcpy(p, s, len);
	return (p);
}
char	*ft_strrev_bonus(char *s)
{
	char	*p1;
	char	*p2;
	char	ch;

	p1 = s;
	p2 = s + ft_strlen(s) - 1;
	while (p1 < p2)
	{
		ch = *p1;
		*p1 = *p2;
		*p2 = ch;
		p1++;
		p2--;
	}
	return (s);
}
char	*ft_itoa(int n)
{
	char	temp[12];
	int		sign;
	int		i;

	i = 0;
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	while (n)
	{
		temp[i++] = (n % 10) * sign + '0';
		n = n / 10;
	}
	if (sign < 0)
		temp[i++] = '-';
	if (0 == i)
		temp[i++] = '0';
	temp[i] = 0;
	return (ft_strdup(ft_strrev_bonus(temp)));
}

void	ft_putstr_fd(char *s, int fd)
{
	if (0 < fd && s != 0)
		write(fd, s, ft_strlen(s));
}
//////---------------------------//////---------------------------//////---------------------------//////---------------------------

typedef struct	s_info
{
	char		flag;
	int			width;
	char		dot;
	int			length;
	char		type;
}				t_info;

void	init_info(t_info *info)
{
	ft_memset(info, 0, sizeof(t_info));
}

char	is_type(char ch)
{
	const char	*p = ft_strchr(TYPE, ch); 
	return (p ? *p : 0);
}

int		is_flag(char ch)
{
	return (ft_strchr(FLAG, ch) ? 1 : 0);
}
void	print_info(t_info *info)
{
	printf("info->flag : [%c]\n", info->flag);
	printf("info->width : [%d]\n", info->width);
	printf("info->dot : [%c]\n", info->dot);
	printf("info->length : [%d]\n", info->length);
	printf("info->type : [%c]\n", info->type);
}


char	*set_info_w_l(va_list ap, t_info *info, char *p)
{
	int		value;

	if (*p == '*')
	{
		value = va_arg(ap, int);
		if (value < 0)
		{
			value *= -1;
			info->flag = '-';
		}
		p++;
	}
	else
	{
		value = ft_atoi(p);
		while (ft_isdigit(*p) || *p == '-' || *p == '+')
			p++;
	}
	if (info->dot)
		info->length = value;
	else
		info->width = value;
	return (p);
}

char 	*set_info(va_list ap, t_info *info, char *p)
{
	if (is_flag(*p))
		info->flag = *p++;
	p = set_info_w_l(ap, info, p);
	if (*p == '.')
	{
		info->dot = *p++;
		p = set_info_w_l(ap, info, p);
	}
	if (is_type(*p))
		info->type = *p;
	return (p);
}

int		print_char_while(char ch, size_t i)
{
	size_t	j;

	j = 0;
	while (j++ < i)
		ft_putchar_fd(ch, 1);
	return (i);
}
int		print_char(t_info *info, char ch)
{
	size_t	len;

	len = 0;
	if (info->width > 1)
	{
		if (info->flag == '-')
		{
			ft_putchar_fd(ch, 1);
			len += print_char_while(' ', info->width - 1);
		}
		else if (info->flag == '0')
		{
			len += print_char_while('0', info->width - 1);
			ft_putchar_fd(ch, 1);
		}
		else if (info->flag == 0)
		{
			len += print_char_while(' ', info->width - 1);
			ft_putchar_fd(ch, 1);
		}
	}
	else
		ft_putchar_fd(ch, 1);
	return (len + 1);	
}

int		print_nbr(t_info *info, int n)
{
	char	*buf;
	size_t	len;

	buf = ft_itoa(n);
	len = ft_strlen(buf);
	if (info->width > len)
	{
		if (info->flag == '-')
		{
			ft_putstr_fd(buf, 1);
			len += print_char_while(' ', info->width - len);
		}
		else if (info->flag == '0')
		{
			len += print_char_while('0', info->width - len);
			ft_putstr_fd(buf, 1);
		}
		else if (info->flag == 0)
		{
			len += print_char_while(' ', info->width - len);
			ft_putstr_fd(buf, 1);
		}
	}
	else
		ft_putstr_fd(buf, 1);	
	free(buf);
	return ((info->width > len) ? info->width : len);
}
int		ft_hex_bonus(size_t n, char *buf_17)
{
	const char	*base = "0123456789abcdef";
	size_t		i;

	if (n >> 4)
		i = ft_hex_bonus(n >> 4, buf_17);
	else
		i = 0;
	buf_17[i] = base[n & 0x0f];
	buf_17[i + 1] = 0;
	return (i + 1);
}

int		print_hex(t_info *info, size_t p)
{
	size_t	len;
	char	buf[19];
	
	ft_hex_bonus(p, &buf[2]);
	buf[0] = '0';
	buf[1] = 'x';
	len = ft_strlen(buf);
	if (info->width > len)
	{
		if (info->flag == '-')
		{
			ft_putstr_fd(buf, 1);
			len += print_char_while(' ', info->width - len);
		}
		else if (info->flag == '0')
		{
			len += print_char_while('0', info->width - len);
			ft_putstr_fd(buf, 1);
		}
		else if (info->flag == 0)
		{
			len += print_char_while(' ', info->width - len);
			ft_putstr_fd(buf, 1);
		}
	}
	else
		ft_putstr_fd(buf, 1);
	return (len);
}

// info를 바탕으로 출력
// 출력된 길이 반환
size_t	print_value(va_list ap, t_info *info)
{
	size_t	len;

	len = 0;

	if (info->type == '%')
		len = print_char(info, '%');
	else if (info->type == 'c')
		len = print_char(info, va_arg(ap, int));
	//else if (info->type == 's')
	//	len = print_str(info, va_arg(ap, char*));
	else if (info->type == 'i' || info->type == 'd')
		len = print_nbr(info, va_arg(ap, int));
	else if (info->type == 'p')
		len = print_hex(info, va_arg(ap, size_t));
	//else if (info->type == 'u' || info->type == 'x' || info->type == 'X')
	//	len = print_char(info, va_arg(ap, unsigned int));
	
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_info	info;
	char	*p;
	int		len;

	p = (char*)format;
	len = 0;
	va_start(ap, format);
	while (*p)
	{
		if (*p != '%')
		{
			ft_putchar_fd(*p, 1);
			len++;
		}
		else
		{
			init_info(&info);
			p = set_info(ap, &info, ++p);
			len += print_value(ap, &info);
			//print_info(&info);
		}
		p++;
	}
	va_end(ap);
	return (len);
}





int		main()
{
	int a, b;

	a = printf("1asd %%]\n");
	b = ft_printf("2asd %%]\n");
	printf("%d %d------------\n", a, b);
	
	a = printf("1asd %10d]\n", -123);
	b = ft_printf("2asd %10d]\n", -123);
	printf("%d %d------------\n", a, b);

	a = printf("1asd %-4d]\n", -12345);
	b = ft_printf("2asd %-4d]\n", -12345);
	printf("%d %d------------\n", a, b);

	a = printf("1asd %*d]\n", 5,-123);
	b = ft_printf("2asd %*d]\n", 5,-123);
	printf("%d %d------------\n", a, b);

	a = printf("1asd %0*c]\n", 6,'A');
	b = ft_printf("2asd %0*c]\n", 6, 'A');
	printf("%d %d------------\n", a, b);

	a = printf("1p %*p]\n", 16, &a);
	b = ft_printf("2p %*p]\n", 16, &a);
	printf("%d %d------------\n", a, b);

	return (0);
}

