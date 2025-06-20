#include "../push_swap.h"

int	ft_sort_checker(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	node_min(t_stack *stack)
{
	long	min;
	t_stack	*node_min;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			node_max = stack;
		}
		stack = stack->next;
	}
	return (node_min);
}

t_stack	node_max(t_stack *stack)
{
	long	max;
	t_stack	*node_max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			node_max = stack;
		}
		stack = stack->next;
	}
	return (node_max);
}
