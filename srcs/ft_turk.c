#include "../push_swap.h"

void	ft_turk(t_stack **a, t_stack **b)
{
	int	stack_size;
	
	stack_size = ft_list_size(a);
	if (stack_size-- > 3 && !ft_sort_checker(*a))
		ft_pb(a, b);
	if (stack_size-- > 3 && !ft_sort_checker(*a))
		ft_pb(a, b);
	while (stack_size-- > 3 && !sort_checker)
	{
		prep_stacks(a, b);

	}
	ft_sort_three(a);
	while (*b)
	{
	
	}
}
