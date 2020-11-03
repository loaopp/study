#include <stdio.h>
#include "libft.h"

int	main()
{
	char **l;
	char *p = "ab dw s w  s  d";

	l = ft_split(p, ' ');

	while (*l)
	{
		puts(*l);
		l++;
	}

	return (0);
}
