/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:43:19 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/26 17:04:13 by mipinhei         ###   ########.fr       */
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
		ft_pullback_a(a, b);
	}
}
