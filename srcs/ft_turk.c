/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:30:49 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/01 17:02:10 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	ft_turk(t_stack **a, t_stack **b)
{
	int	stack_size;
	int count = 0;
	
	stack_size = ft_list_size(*a);
	if (stack_size-- > 3 && !ft_sort_checker(*a))
		ft_pb(a, b);
		printf("OP number:%i A stack size:%i B stack size:%i\n", count++, ft_list_size(*a), ft_list_size(*b));
	if (stack_size-- > 3 && !ft_sort_checker(*a))
		ft_pb(a, b);
		printf("OP number:%i A stack size:%i B stack size:%i\n", count++, ft_list_size(*a), ft_list_size(*b));
	while (stack_size-- > 3 && !ft_sort_checker(*a))
	{
		prep_stack_a(a, b);
		printf("OP number:%i A stack size:%i B stack size:%i\n", count++, ft_list_size(*a), ft_list_size(*b));
		ft_rushb(a, b);
	}
		printf("OP number:%i A stack size:%i B stack size:%i\n", count++, ft_list_size(*a), ft_list_size(*b));
	ft_sort_three(a);
		printf("OP number:%i A stack size:%i B stack size:%i\n", count++, ft_list_size(*a), ft_list_size(*b));
	while (*b)
	{
		prep_stack_b(a, b);
		prep_rot(a, b, (*b)->target, 0);
		ft_pa(a, b);
	}
	ft_indexing(*a);
	check_top(a);
}
