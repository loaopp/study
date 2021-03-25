#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int get_val(va_list ap, int n)
{
	va_list ap2;
	va_copy(ap2, ap);
	int x;

	x = 0;
	for (int i=0; i<n; i++)
	{
		x = va_arg(ap2, int);
	}
	return (x);
}

void add(int x, ...)
{
	va_list ap;
	va_start(ap, x);
	
	printf("%c\n", va_arg(ap, int));
	printf("%f\n", va_arg(ap, double));
	
	printf("%d\n", get_val(ap,1));

	//printf("%p\n", ap);
	//printf("%d\n", *(ap+4));
	printf("%d\n", va_arg(ap, int));
	printf("%s\n", va_arg(ap, char*));
	printf("%d\n", va_arg(ap, int));
	va_end(ap);
}

void hax(size_t s)
{
	size_t a = s & 15;

	printf("%zu	%zx\n", s, s);
	printf("%zu	%zx\n", a, a);
	a = s >> 4 & 15;
	printf("%zu	%zx\n", a, a);
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
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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



int		ft_isspace_bonus(int c)
{
	return (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r');
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
void	ft_puthex_fd_bonus(size_t n, int fd)
{
	const char		base[] = "0123456789abcdef";
	const size_t	mask = 0x0f;
	
	if (n >> 4)
		ft_puthex_fd_bonus(n >> 4, fd);
	write(fd, &base[n & mask], 1);
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


int main()
{
	char str[] = "asdv23";
	char b[17];

	printf("%*.2x]\n", -5,12345);
	printf("%06x]\n", 12345);
	printf("%20.2x]\n", 12345);
	printf("--------\n");
	printf("%*.2d]\n", -5,12345);
	printf("%010d]\n", 12345);
	printf("%-14d]\n", 12345);
	printf("--------\n");
	printf("%*.2s]\n", -5,"123456");
	printf("%010s]\n", "123456");
	printf("%-14s]\n", "123456");
	printf("--------\n");
	printf("%*.2f]\n", -5,12345.52322);
	printf("%010u]\n", 12345);
	printf("%-14u]\n", 12345);
	printf("--------\n");
	printf("%*s]\n", 7,"abcde");
	printf("%-10.2s]\n", "abcde");
	printf("%0*.7s]\n", 14,"abcde");
	printf("--------\n");	
	return 0;
}
