/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:43:54 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/04 12:22:44 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sort_checker(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	*node_min(t_stack *stack)
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
			node_min = stack;
		}
		stack = stack->next;
	}
	return (node_min);
}

t_stack	*node_max(t_stack *stack)
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

void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	if (ft_list_size(*a) == 2)
		ft_sa(a, 1);
	else if (ft_list_size(*a) == 3)
		ft_sort_three(a);
	else
		ft_turk(a, b);
}
