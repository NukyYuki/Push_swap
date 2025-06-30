/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:10:04 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/30 13:11:37 by mipinhei         ###   ########.fr       */
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
	while((*a)->content != min->content)
	{
		if (min->below_median)
			ft_rra(a, 1);
		else
			ft_ra(a, 1);
	}
}
