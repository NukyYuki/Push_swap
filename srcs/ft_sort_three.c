#include "../push_swap.h"

void	ft_sort_three(t_stack **a)
{
	t_stack	*max_node;

	max_node = node_max(*a);
	if(a == max_node)
		ft_ra(a, 1);
	else
		ft_rra(a, 1);
	if (*a->content > *a->next->content)
		ft_sa(a, 1);
}
