/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:10:04 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/03 13:11:18 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	check_top(t_stack **a)
{
	t_stack	*min;

	if (!*a)
		return ;
	min = node_min(*a);
	while ((*a)->content != min->content)
	{
		if (min->top_stack)
			ft_rra(a, 1);
		else
			ft_ra(a, 1);
	}
}

void	ft_rusha(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	if (!a || !b)
		return ;
//	prep_stack_a(a, b);
	cheapest = ft_cheapest_node(*b);
	if (!cheapest || !cheapest->target)
		return ;
	prep_rot_a(a, b, cheapest);
	setup_push(b, cheapest, 0);
	setup_push(a, cheapest->target, 1);
	ft_pa(a, b);
//	prep_stack_b(a, b);
//	ft_cheapest_node(*b);
}

void	prep_rot_a(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (!cheapest || !cheapest->target)
		return ;
	if (cheapest->top_stack == 0 && cheapest->target->top_stack == 0)
	{
		while ((*a)->content != cheapest->target->content
			&& (*b)->content != cheapest->content)
		{
			ft_rr(a, b);
			ft_indexing(*a);
			ft_indexing(*b);
		}
	}
	if (cheapest->top_stack == 1 && cheapest->target->top_stack == 1)
	{
		while ((*a)->content != cheapest->target->content
			&& (*b)->content != cheapest->content)
		{
			ft_rrr(a, b);
			ft_indexing(*a);
			ft_indexing(*b);
		}
	}
}
