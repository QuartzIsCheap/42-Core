
#include <stdlib.h>

#include "libft.h"
#include "stack.h"
#include "stack/creation.h"

int main(int argc, char *argv[])
{
	t_stack	stack;

	if (try_parse_stack(argc, argv, &stack) < 0)
	{
		ft_putendl_fd("Error", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
