#include <stdio.h>
#include "libft.h"

int	main()
{
	ft_putnbr_fd(-1, 1);
	puts("");
	ft_putnbr_fd(2147483647, 1);
	puts("");
	ft_putnbr_fd(-2147483649, 1);
	puts("");

	return (0);
}
