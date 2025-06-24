#include "../push_swap.h"

void	prep_stacks(t_stack **a, t_stack **b)
{
	ft_median(a);
	ft_median(b);
}

void	ft_median(t_stack *stack)
{
	int	i;
	int	median;

	if (!*stack)
		return ;
	median = ft_list_size(stack) / 2;
	while (stack)
	{
		if (i <= median)
			stack->below_median = 1;
		else
			stack->below_median = 0;
		stack = stack->next;
		i++;
	}
}

void		a_target(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*target;

}
