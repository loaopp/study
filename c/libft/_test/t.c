#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = 0;
	while (*s)
	{
		if (*s == c)
			p = (char*)s;
		s++;
	}
	if (*s == '\0')
		return ((char*)s);
	return (p);
}


char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	return (0);
}

int main()
{
	char *str = "test abcmanc12345";
	char *p;

	p = ft_strchr(str, '\0');


	printf("%p\n", str);
	printf("%p\n", p);

	return 0;
}
