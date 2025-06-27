/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:30:49 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/27 12:33:16 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_turk(t_stack **a, t_stack **b)
{
	int	stack_size;
	
	stack_size = ft_list_size(*a);
	if (stack_size-- > 3 && !ft_sort_checker(*a))
		ft_pb(a, b);
	if (stack_size-- > 3 && !ft_sort_checker(*a))
		ft_pb(a, b);
	while (stack_size-- > 3 && !ft_sort_checker(*a))
	{
		prep_stack_a(a, b);
		ft_rushb(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		prep_stack_b(a, b);
		prep_rot(a, b, (*b)->target, 0);
		ft_pb(a, b);
	}
	ft_indexing(*a);
	check_top(a);
}
