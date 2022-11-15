#include <stdio.h>
#include <stdlib.h>

#include "ft_printf.h"

int	main() {
	void *p1 = 0, *p2 = (void *)1010;
	int count = ft_printf("Hello %s!%%\n%c\n%x\n%d\n%u\n%p\n%p\n%c\n", "world", 'l', -154, -154, -154, p1, p2, 0);
	ft_printf("Count : %d\n\n\n", count);
	//count = printf("Hello %s!%%\n%c\n%x\n%d\n%u\n%p\n%p\n%c\n", "world", 'l', -154, -154, -154, p1, p2, 0);
	//printf("Count : %d\n", count);

	return (EXIT_SUCCESS);
}
