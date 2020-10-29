#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
	char *str = "test abcmanc12345";
	char *p;

	p = ft_strchr(str, '\0');


	printf("%p\n", str);
	printf("%p\n", p);

	return 0;
}
