#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (*(p1 + i) - *(p2 + i))
			return (*(p1 + i) - *(p2 + i));
		i++;
	}
	return (0);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_b;
	size_t	len_l;
	size_t	i;

	if (little == 0)
		return ((char*)big);
	len_b = ft_strlen(big);
	len_l = ft_strlen(little);
	if (len_b < len_l || len < len_l)
		return (0);
	if (len_b < len)
		i = len_b;
	else
		i = len;
	while (len_l <= i--)
	{
		if (ft_memcmp(big, little, len_l) == 0)
			return ((char*)big);
		big++;
	}
}


int main()
{
	char str1[10] = "012345";
	char str2[10] = "23";

	puts(memcpy(str1+1,str1, 5));


	return 0;
}
