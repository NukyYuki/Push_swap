/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_rushb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:51:51 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/01 16:00:24 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prep_rot(t_stack **a, t_stack **b, t_stack *cheapest, int check)
{
	if (check == 1)
	{
		while (*b != cheapest->target && *a != cheapest)
		{
			ft_rr(a, b);
			ft_indexing(*a);
			ft_indexing(*b);
		}
	}
	else if (check == 0)
	{
		while (*b != cheapest->target && *a != cheapest)
		{
			ft_rrr(a, b);
			ft_indexing(*a);
			ft_indexing(*b);
		}
	}
	else
		return ;
}

t_stack	*check_stack(t_stack **stack, t_stack *cheapest)
{
	t_stack	*check;

	check = *stack;
	while (check->next)
	{
		if (check == cheapest)
			return (check);
		check = check->next;
	}
	return (NULL);
}

void	setup_push(t_stack **stack, t_stack *cheapest, int check)
{
	t_stack	*check_node;

	check_node = check_stack(stack, cheapest);
	if (check_node)
	{
		while (*stack != cheapest)
		{
			if (check == 1)
			{
				if (cheapest->top_stack == 0)
					ft_ra(stack, 1);
				else
					ft_rra(stack, 1);
			}
			else if (check == 0)
			{
				if (cheapest->top_stack == 0)
					ft_rb(stack, 1);
				else
					ft_rrb(stack, 1);
			}
		}
	}
}

void	ft_rushb(t_stack **a, t_stack **b)
{
	int		stack_size;
	t_stack	*cheapest;

	if (!a || !b)
		return ;
	stack_size = ft_list_size(*a);
	cheapest = ft_cheapest_node(*a);
	if (cheapest->top_stack == 0 && cheapest->target->top_stack == 0)
		prep_rot(a, b, cheapest, 0);
	else if (cheapest->top_stack == 1 && cheapest->target->top_stack == 1)
		prep_rot(a, b, cheapest, 1);
	setup_push(a, cheapest, 1);
	setup_push(b, cheapest->target, 0);
	ft_pb(a, b);
}
