/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_rushb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:51:51 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/02 17:00:36 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	prep_rot_b(t_stack **a, t_stack **b, t_stack *cheapest, int check)
{
	if (!cheapest || !cheapest->target)
		return ;
	if (check == 1)
	{
		while ((*b && (*b)->content != cheapest->target->content) 
				&& (*a && (*a)->content != cheapest->content))
		{
			ft_rr(a, b);
			ft_indexing(*a);
			ft_indexing(*b);
		}
	}
	else if (check == 0)
	{
		while ((*b && (*b)->content != cheapest->target->content) 
				&& (*a && (*a)->content != cheapest->content))
		{
			ft_rrr(a, b);
			ft_indexing(*a);
			ft_indexing(*b);
		}
	}
}

int	valid_node(t_stack *stack, int content)
{
	while (stack)
	{
		if (stack->content == content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	setup_push(t_stack **stack, t_stack *cheapest, int check)
{
	if (!*stack || !cheapest)
		return ;
	if (!valid_node(*stack, cheapest->content))
		return ;
	while ((*stack)->content != cheapest->content)
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
		ft_indexing(*stack);
	}
}


void	ft_rushb(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	if (!a || !b)
		return ;
	prep_stack_a(a, b);
	cheapest = ft_cheapest_node(*a);
	if (!cheapest || !cheapest->target)
		return ;
	if (cheapest->top_stack == 0 && cheapest->target->top_stack == 0)
		prep_rot_b(a, b, cheapest, 0);
	else if (cheapest->top_stack == 1 && cheapest->target->top_stack == 1)
		prep_rot_b(a, b, cheapest, 1);
	setup_push(a, cheapest, 1);
	setup_push(b, cheapest->target, 0);
	ft_pb(a, b);
	prep_stack_a(a, b);
	ft_cheapest_node(*a);
}
