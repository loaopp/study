#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
	char *str = "test abcm";
	char p[10] = "123456789";
	char *a;
	p[5] = '\0';
	a = memccpy(p, str, '5', 30);
	puts(p);
	puts(a);
	return 0;
}
