/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_rushb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:51:51 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/26 17:19:48 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	prep_push_to_b(t_stack **stack, t_stack *cheapest, int check)
{
	while (*stack != cheapest)
	{
		if (check == 1)
		{
			if (cheapest->below_median == 0)
				ft_ra(stack, 1);
			else
				ft_rra(stack, 1);
		}
		else if (check == 0)
		{
			if (cheapest->below_median == 0)
				ft_rb(stack, 1);
			else
				ft_rrb(stack, 1);
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
	if (cheapest->below_median == 0 && cheapest->target->below_median == 0)
		prep_rot(a, b, cheapest, 0);
	else if (cheapest->below_median == 1 && cheapest->target->below_median == 1)
		prep_rot(a, b, cheapest, 1);
	prep_push_b(a, cheapest, 1);
	prep_push_b(b, cheapest, 0);
	ft_pb(a, b);
}
