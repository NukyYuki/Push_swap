/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_utils_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:42:56 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/30 13:39:30 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prep_stack_a(t_stack **a, t_stack **b)
{
	ft_indexing(*a);
	ft_indexing(*b);
	a_target(*a, *b);
	operations_cost_a(*a, *b);
	find_cheapest(*a);
}

void	ft_indexing(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = ft_list_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->below_median = 0;
		else
			stack->below_median = 1;
		stack = stack->next;
		i++;
	}
}

void	a_target(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*target;
	long	match_nbr;

	while (a)
	{
		match_nbr = LONG_MIN;
		current = b;
		while (current)
		{
			if (current->content < a->content
				&& current->content > match_nbr)
			{
				match_nbr = current->content;
				target = current;
			}
			current = current->next;
		}
		if (match_nbr == LONG_MIN)
			a->target = node_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	operations_cost_a(t_stack *a, t_stack *b)
{
	int	a_size;
	int	b_size;

	a_size = ft_list_size(a);
	b_size = ft_list_size(b);
	while (a)
	{
		a->op_cost = 0;
		if (a->below_median == 1)
			a->op_cost = a->index;
		else
			a->op_cost = a_size - a->index;
		a = a->next;
	}
}

void	find_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	long	min_val;

	if (!stack)
		return ;
	cheapest = stack;
	min_val = LONG_MAX;
	while (stack)
	{
		stack->cheapest = 0;
		if (stack->op_cost < min_val)
		{
			min_val = stack->op_cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = 1;
}
