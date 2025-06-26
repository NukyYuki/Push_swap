#include "../push_swap.h"

void	ft_turk(t_stack **a, t_stack **b)
{
	int	stack_size;
	
	stack_size = ft_list_size(*a);
	if (stack_size-- > 3 && !ft_sort_checker(*a))
		ft_pb(a, b);
	if (stack_size-- > 3 && !ft_sort_checker(*a))
		ft_pb(a, b);
	while (stack_size-- > 3 && !ft_sort_checker(*a))
	{
		prep_stack_a(a, b);
		ft_rushb(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		prep_stack_b(a, b);
		prep_rot(a, (*b)->target, 0);
		ft_pb(a, b, 1);
	}
	ft_indexing(*a);
	check_top(a);
}
