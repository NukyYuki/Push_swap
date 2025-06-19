#include "../push_swap.h"

void	ft_stack_init(t_stack **a, char **av)
{
	long	n;
	int		i;

	while (av[i])
	{
		if (ft_valid_numbers(av[i] == 1)
			free_err(a);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_err(a);
		if (ft_valid_list(*a, n) == 1)
			free_err(a);
		add_node(a, (int)n);
		i++;
	}
}
