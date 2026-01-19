#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("%i\n", printf(0));
	printf("%i\n", ft_printf(0));

	return (0);
}
