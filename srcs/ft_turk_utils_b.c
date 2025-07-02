/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_utils_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:32:18 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/02 15:49:25 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prep_stack_b(t_stack **a, t_stack **b)
{
	ft_indexing(*a);
	ft_indexing(*b);
	b_target(*a, *b);
	operations_cost_b(*a, *b);
	find_cheapest(*b);
}

void	b_target(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*target;
	long	match_nbr;

	while (b)
	{
		match_nbr = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->content > b->content && current->content < match_nbr)
			{
				match_nbr = current->content;
				target = current;
			}
			current = current->next;
		}
		if (match_nbr == LONG_MAX)
			b->target = node_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	operations_cost_b(t_stack *a, t_stack *b)
{
	int	a_size;
	int	b_size;
	int	a_median;
	int	b_median;

	a_size = ft_list_size(a);
	b_size = ft_list_size(b);
	a_median = a_size / 2;
	b_median = b_size / 2;
	while (b)
	{
		if (b->index <= b_median)
			b->op_cost = b->index;
		else
			b->op_cost = b_size - a->index;
		if (b->target)
		{
				if (b->target->index <= a_median)
					b->op_cost += b->target->index;
				else
					b->op_cost += a_size - b->target->index;
		}
		b = b->next;
	}
}
