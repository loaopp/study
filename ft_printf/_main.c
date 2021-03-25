#include "ft_printf.h"

void ttt(int a, ...)
{
	va_list ap;

	va_start(ap, a);

	while (a)
	{
		printf("%d", va_arg(ap, int));
		a--;
	}

	va_end(ap);
}


int		main()
{
	

        char    c = 'a';
        int             d = 2147483647;
        int             e = -2147483648;
		int             i = 8;
        int             j = -12;
        int             k = 123456789;
        int             l = 0;
        int             m = -12345678;
        char    *n = "abcdefghijklmnop";



		int             a = -4;
        int             b = 0;
        int             f = 42;
        int             g = 25;
        int             h = 4200;

        char    *o = "-a";
        char    *p = "-12";
        char    *q = "0";
        char    *r = "%%";
        char    *s = "-2147483648";
        char    *t = "0x12345678";
        char    *u = "-0";

		int xx, yy;

//printf("this %u number]\n", 0);
//ft_printf("this %u number]\n", 0);
//printf("%3u]\n", 0);
//ft_printf("%3u]\n", 0);
//printf("%-3u]\n", 0);
//ft_printf("%-3u]\n", 0);
//printf("a%ub%uc%ud]\n", 0, 55555, 100000);
//ft_printf("a%ub%uc%ud]\n", 0, 55555, 100000);
//printf("%u]\n", 4294967295 + 1);
//ft_printf("%u]\n", 4294967295 + 1);
//printf("%-12.*s%98.128s%--8p%095.*i%00182.193x]\n" ,139,"o=Z*[","9S14l$RgnTv`-Wm",(void*)3870843096944218592lu,-156,201214506,1134523837u);
//ft_printf("%-12.*s%98.128s%--8p%095.*i%00182.193x]\n" ,139,"o=Z*[","9S14l$RgnTv`-Wm",(void*)3870843096944218592lu,-156,201214506,1134523837u);
//printf("%-66p%-90c%--*.69x%0045.*u]\n" ,(void*)9420165689360028937lu,-29,-122,174318236u,-127,2553740548u);
//ft_printf("%-66p%-90c%--*.69x%0045.*u]\n" ,(void*)9420165689360028937lu,-29,-122,174318236u,-127,2553740548u);


//a = -2;
//while(a < 5) //T70-177
//{
//		b = -2;
//		while (b < 5)
//		{
//				printf("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s]\n", \
//				a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
				
//				ft_printf("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s]\n", \
//				a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);

//				printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s]\n", \
//				 a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);

//				ft_printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s]\n", \
//				a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
//				b++;

//				printf("---- %d    %d ----\n", a, b);
//		}
//		a++;
//}


//printf("{%0.*s}]\n", -5, "42");
//ft_printf("{%0.*s}]\n", -5, "42");
printf("{%05.*d}\n", -15, 42);
ft_printf("{%05.*d}\n", -15, 42);

//ft_printf("test %% asd %p 1111 %p\n", &a, 0);

//printf("%s%s]\n", "hello", "world");
//ft_printf("%s%s]\n", "hello", "world");
//printf("..%s stuff %s]\n", "a", "b");
//ft_printf("..%s stuff %s]\n", "a", "b");
//printf("this %s is %s]\n", "hello", "");
//ft_printf("this %s is %s]\n", "hello", "");
//printf("this %s is %s]\n", "", "hello");
//ft_printf("this %s is %s]\n", "", "hello");
//printf("%s%s%s]\n", "1", "2", "3's a charm");
//ft_printf("%s%s%s]\n", "1", "2", "3's a charm");
//printf("%.3s%.2s]\n", "holla", "bitch");
//ft_printf("%.3s%.2s]\n", "holla", "bitch");
//printf("%.2s%.7s]\n", "hello", "world");
//ft_printf("%.2s%.7s]\n", "hello", "world");
//printf("%.7s%.2s]\n", "hello", "world");
//ft_printf("%.7s%.2s]\n", "hello", "world");
//printf("%.5s%7s]\n", "yo", "boi");
//ft_printf("%.5s%7s]\n", "yo", "boi");
//printf("%7.7s%7.7s]\n", "hello", "world");
//ft_printf("%7.7s%7.7s]\n", "hello", "world");
//printf("%3.7s%7.7s]\n", "hello", "world");
//ft_printf("%3.7s%7.7s]\n", "hello", "world");
//printf("%7.7s%3.7s]\n", "hello", "world");
//ft_printf("%7.7s%3.7s]\n", "hello", "world");
//printf("%3.7s%3.7s]\n", "hello", "world");
//ft_printf("%3.7s%3.7s]\n", "hello", "world");
//printf("%7.3s%7.7s]\n", "hello", "world");
//ft_printf("%7.3s%7.7s]\n", "hello", "world");
//printf("%3.3s%7.7s]\n", "hello", "world");
//ft_printf("%3.3s%7.7s]\n", "hello", "world");
//printf("%7.3s%3.7s]\n", "hello", "world");
//ft_printf("%7.3s%3.7s]\n", "hello", "world");
//printf("%3.3s%3.7s]\n", "hello", "world");
//ft_printf("%3.3s%3.7s]\n", "hello", "world");
//printf("%7.7s%7.3s]\n", "hello", "world");
//ft_printf("%7.7s%7.3s]\n", "hello", "world");
//printf("%3.7s%7.3s]\n", "hello", "world");
//ft_printf("%3.7s%7.3s]\n", "hello", "world");
//printf("%7.7s%3.3s]\n", "hello", "world");
//ft_printf("%7.7s%3.3s]\n", "hello", "world");
//printf("%3.7s%3.3s]\n", "hello", "world");
//ft_printf("%3.7s%3.3s]\n", "hello", "world");
//printf("%7.3s%7.3s]\n", "hello", "world");
//ft_printf("%7.3s%7.3s]\n", "hello", "world");
//printf("%3.3s%7.3s]\n", "hello", "world");
//ft_printf("%3.3s%7.3s]\n", "hello", "world");
//printf("%7.3s%3.3s]\n", "hello", "world");
//ft_printf("%7.3s%3.3s]\n", "hello", "world");
//printf("%3.3s%3.3s]\n", "hello", "world");
//ft_printf("%3.3s%3.3s]\n", "hello", "world");

	//printf("123456789012345678901234567890\n");
	//printf("%p]\n", NULL);
	//printf("%0p]\n", NULL);
	//printf("%020p]\n", NULL);
	//printf("%020p]\n", &xx);
	//printf("%020.p]\n", NULL);
	//printf("%020.p]\n", &xx);
	//printf("%020.0p]\n", NULL);
	//printf("%020.0p]\n", &xx);
	//printf("%020.4p]\n", NULL);
	//printf("%020.4p]\n", &xx);
	//printf("%020.15p]\n", NULL);
	//printf("%020.15p]\n", &xx);
	//printf("123456789012345678901234567890\n");
	//printf("%-20p]\n", NULL);
	//printf("%-20p]\n", &xx);
	//printf("%-20.p]\n", NULL);
	//printf("%-20.p]\n", &xx);
	//printf("%-20.0p]\n", NULL);
	//printf("%-20.0p]\n", &xx);
	//printf("%-20.4p]\n", NULL);
	//printf("%-20.4p]\n", &xx);
	//printf("%-10.15p]\n", NULL);
	//printf("%-10.15p]\n", &xx);
	//puts("------------");
	//ft_printf("123456789012345678901234567890\n");
	//ft_printf("%p]\n", NULL);
	//ft_printf("%0p]\n", NULL);
	//ft_printf("%020p]\n", NULL);
	//ft_printf("%020p]\n", &xx);
	//ft_printf("%020.p]\n", NULL);
	//ft_printf("%020.p]\n", &xx);
	//ft_printf("%020.0p]\n", NULL);
	//ft_printf("%020.0p]\n", &xx);
	//ft_printf("%020.4p]\n", NULL);
	//ft_printf("%020.4p]\n", &xx);
	//ft_printf("%020.15p]\n", NULL);
	//ft_printf("%020.15p]\n", &xx);
	//ft_printf("123456789012345678901234567890\n");
	//ft_printf("%-20p]\n", NULL);
	//ft_printf("%-20p]\n", &xx);
	//ft_printf("%-20.p]\n", NULL);
	//ft_printf("%-20.p]\n", &xx);
	//ft_printf("%-20.0p]\n", NULL);
	//ft_printf("%-20.0p]\n", &xx);
	//ft_printf("%-20.4p]\n", NULL);
	//ft_printf("%-20.4p]\n", &xx);
	//ft_printf("%-10.15p]\n", NULL);
	//ft_printf("%-10.15p]\n", &xx);	
	
	//printf("%s]\n", 0);
	//ft_printf("%s]\n", 0);
	//printf("%1.3s]\n", 0);
	//ft_printf("%1.3s]\n", 0);
	//printf("%5.s]\n", 0);
	//ft_printf("%5.s]\n", 0);


	//printf("neg1 %*s\n", -9, "coucou");
	//ft_printf("neg1 %*s\n", -9, "coucou");
	//printf("neg2 %*.*s\n", -9, 4, "coucou");
	//ft_printf("neg2 %*.*s\n", -9, 4, "coucou");
	//printf("neg3 %*s\n", -9, NULL);
	//ft_printf("neg3 %*s\n", -9, NULL);
	//printf("neg5 %*s\n", -10, "coucou");
	//ft_printf("neg5 %*s\n", -10, "coucou");
	//printf("neg6 %*s\n", -15, "coucou");
	//ft_printf("neg6 %*s\n", -15, "coucou");
	//printf("neg7 %*.*s\n", -16, 15, "coucou");
	//ft_printf("neg7 %*.*s\n", -16, 15, "coucou");
	//printf("neg8 %*.*s\n", -16, 15, "coucou");
	//ft_printf("neg8 %*.*s\n", -16, 15, "coucou");
	//printf("neg9 %*.*s\n", 15, 155, "coucou");
	//ft_printf("neg9 %*.*s\n", 15, 155, "coucou");
	//printf("neg10 %*.*s\n", -15, 15, "coucou");
	//ft_printf("neg10 %*.*s\n", -15, 15, "coucou");
	//printf("neg11 %*.*s\n", -15, 15, "coucou");
	//ft_printf("neg11 %*.*s\n", -15, 15, "coucou");
// ----- 	d		-------------------------------------------------------------------------------------
		//printf("[%10d][%--10d][%010d][%10.d][%.d](  )[%.*d][%2d][%3.2d][%010.5d]\n", \
		//		1234, 1234, 1234, 1234, 1234, -10, 1234, 1234, 1234, 1234);
		//ft_printf("[%10d][%--10d][%010d][%10.d][%.d](  )[%.*d][%2d][%3.2d][%010.5d]\n", \
		//		1234, 1234, 1234, 1234, 1234, -10, 1234, 1234, 1234, 1234);
		//printf("[%10d][%--10d][%010d][%10.d][%.d](  )[%.*d][%2d][%3.2d][%010.10d]\n", \
		//		-1234, -1234, -1234, -1234, -1234, -10, -1234, -1234, -1234, -1234);
		//ft_printf("[%10d][%--10d][%010d][%10.d][%.d](  )[%.*d][%2d][%3.2d][%010.10d]\n", \
		//		-1234, -1234, -1234, -1234, -1234, -10, -1234, -1234, -1234, -1234);
		//printf("[%10d][%--10d][%010d][%10.d][%.d](  )[%.*d][%2d][%3.2d][%010.5d]\n", \
		//		0, 0, 0, 0, 0, -10, 0, 0, 0, 0);
		//ft_printf("[%10d][%--10d][%010d][%10.d][%.d](  )[%.*d][%2d][%3.2d][%010.5d]\n", \
		//		0, 0, 0, 0, 0, -10, 0, 0, 0, 0);
//------------------------------------------------------------------------------------------------------
	//char ch = 'A';
	//xx =ft_printf("[%%][%.%][%-%][%0%][%-0.%][%4%][%.4%][%-4%][%-.4%][%4.4%][%-4.4%][%4.%][%*.*%][%*.*%]\n", -2,-4,4,-2);
	//yy=printf("[%%][%.%][%-%][%0%][%-0.%][%4%][%.4%][%-4%][%-.4%][%4.4%][%-4.4%][%4.%][%*.*%][%*.*%]\n", -2,-4,4,-2);
	//printf("%d %d\n", xx, yy);
	//xx =ft_printf("[%c][%.c][%-c][%0c][%-0.c][%4c][%.4c][%-4c][%-.4c][%4.4c][%-4.4c][%4.c][%*.*c][%*.*c]\n", ch,ch,ch,ch,ch,ch,ch,ch,ch,ch,ch,ch, -2,-4,ch,4,-2,ch);
	//yy=printf("[%c][%.c][%-c][%0c][%-0.c][%4c][%.4c][%-4c][%-.4c][%4.4c][%-4.4c][%4.c][%*.*c][%*.*c]\n", ch,ch,ch,ch,ch,ch,ch,ch,ch,ch,ch,ch, -2,-4,ch,4,-2,ch);
	//printf("%d %d\n", xx, yy);

	//printf("[%5p]\n", 0);
	//ft_printf("[%5p]\n", 0);

		
	//printf("[%05p]\n", 0);
	//ft_printf("[%05p]\n", 0);
	
	//printf("[%5.p]\n", &xx);
	//ft_printf("[%5.p]\n", &xx);
	//printf("[%-.0p]\n", 0);
	//ft_printf("[%-.0p]\n", 0);
	//printf("[%-4.p]\n", 0);
	//ft_printf("[%-4.p]\n", 0);
	//puts("--");
	//printf("[%-2.0p]\n", &xx);
	//ft_printf("[%-2.0p]\n",&xx);
	//printf("[%-2.p]\n", &xx);
	//ft_printf("[%-2.p]\n", &xx);
	//printf("[%-2.0p]\n", &xx);
	//ft_printf("[%-2.0p]\n", &xx);
	//printf("[%-2.p]\n", &xx);
	//ft_printf("[%-2.p]\n", &xx);


		//printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j); //T2
		//ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j); //T2
        //printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d); //T3
        //ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d); //T3
        //printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d); //T4
        //ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d); //T4
        //printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d); //T5
        //ft_printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d); //T5
        //printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d\n", i, j, k, l, m, c, e, d); //T6
        //ft_printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d\n", i, j, k, l, m, c, e, d); //T6
        //printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d\n", i, j, k, l, m, c, e, d); //T7
        //ft_printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d\n", i, j, k, l, m, c, e, d); //T7
        //printf("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d\n", i, j, k, l, m, c, e, d); //T8
        //ft_printf("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d\n", i, j, k, l, m, c, e, d); //T8
        //printf("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d\n", i, j, k, l, m, c, e, d); //T9
        //ft_printf("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d\n", i, j, k, l, m, c, e, d); //T9
        //printf("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d\n", i, j, k, l, m, c, e, d); //T10
        //ft_printf("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d\n", i, j, k, l, m, c, e, d); //T10
        //printf("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d\n", i, j, k, l, m, c, e, d); //T11
        //ft_printf("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d\n", i, j, k, l, m, c, e, d); //T11
        //printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", i, j, k, l, m, c, e, d); //T12
        //ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", i, j, k, l, m, c, e, d); //T12
        //printf("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d\n", i, j, k, l, m, c, e, d); //T13
        //ft_printf("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d\n", i, j, k, l, m, c, e, d); //T13
        //printf("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d\n", i, j, k, l, m, c, e, d); //T14
        //ft_printf("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d\n", i, j, k, l, m, c, e, d); //T14
        //printf("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d\n", i, j, k, l, m, c, e, d); //T15
        //ft_printf("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d\n", i, j, k, l, m, c, e, d); //T15
        //printf("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d\n", i, j, k, l, m, c, e, d); //T16
        //ft_printf("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d\n", i, j, k, l, m, c, e, d); //T16
        //printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d\n", i, j, k, l, m, c, e, d); //T17
        //ft_printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d\n", i, j, k, l, m, c, e, d); //T17
        //printf("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d\n", i, j, k, l, m, c, e, d); //T18
        //ft_printf("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d\n", i, j, k, l, m, c, e, d); //T18
        //printf("%-i, %-d, %-d, %-d, %-d, %-d, %-d, %-d\n", i, j, k, l, m, c, e, d); //T19
        //ft_printf("%-i, %-d, %-d, %-d, %-d, %-d, %-d, %-d\n", i, j, k, l, m, c, e, d); //T19
        //printf("%.i, %.d, %.d, %.d, %.d, %.d, %.d, %.d\n", i, j, k, l, m, c, e, d); //T20
        //ft_printf("%.i, %.d, %.d, %.d, %.d, %.d, %.d, %.d\n", i, j, k, l, m, c, e, d); //T20
        //printf("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d\n", i, j, k, l, m, c, e, d); //T21
        //ft_printf("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d\n", i, j, k, l, m, c, e, d); //T21
        //printf("%00i, %00d, %00d, %00d, %00d, %00d, %00d, %00d\n", i, j, k, l, m, c, e, d); //T22
        //ft_printf("%00i, %00d, %00d, %00d, %00d, %00d, %00d, %00d\n", i, j, k, l, m, c, e, d); //T22
        //printf("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d\n", i, j, k, l, m, c, e, d); //T23
        //ft_printf("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d\n", i, j, k, l, m, c, e, d); //T23
        //printf("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d\n", i, j, k, l, m, c, e, d); //T24
        //ft_printf("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d\n", i, j, k, l, m, c, e, d); //T24
        //printf("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d\n", i, j, k, l, m, c, e, d); //T25
        //ft_printf("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d\n", i, j, k, l, m, c, e, d); //T25
        //printf("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d\n", i, j, k, l, m, c, e, d); //T26
        //ft_printf("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d\n", i, j, k, l, m, c, e, d); //T26
        //printf("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d\n", i, j, k, l, m, c, e, d); //T27
        //ft_printf("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d\n", i, j, k, l, m, c, e, d); //T27
        //printf("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d\n", i, j, k, l, m, c, e, d); //T28
        //ft_printf("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d\n", i, j, k, l, m, c, e, d); //T28
        //printf("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d\n", i, j, k, l, m, c, e, d); //T29
        //ft_printf("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d\n", i, j, k, l, m, c, e, d); //T29
        //printf("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d\n", i, j, k, l, m, c, e, d); //T30
        //ft_printf("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d\n", i, j, k, l, m, c, e, d); //T30
        //printf("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d\n", i, j, k, l, m, c, e, d); //T31
        //ft_printf("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d\n", i, j, k, l, m, c, e, d); //T31
        //printf("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d\n", i, j, k, l, m, c, e, d); //T32
        //ft_printf("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d\n", i, j, k, l, m, c, e, d); //T32
        //printf("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d\n", i, j, k, l, m, c, e, d); //T33
        //ft_printf("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d\n", i, j, k, l, m, c, e, d); //T33
		//puts("----");
        //while (a < 5) //T34-69
        //{
        //        xx=printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
        //        yy=ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		//		printf("%d %d\n", xx, yy);
        //       xx= printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
        //        yy=ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		//		printf("%d %d\n", xx, yy);
        //       xx= printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
        //       yy=ft_printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		//		printf("%d %d\n", xx, yy);
        //        xx=printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
        //        yy=ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		//		printf("%d %d\n", xx, yy);
        //        a++;
        //}
		return (0);
}
