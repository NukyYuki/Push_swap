/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_utils_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:32:18 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/01 15:46:32 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prep_stack_b(t_stack **a, t_stack **b)
{
	ft_indexing(*a);
	ft_indexing(*b);
	b_target(*a, *b);
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
