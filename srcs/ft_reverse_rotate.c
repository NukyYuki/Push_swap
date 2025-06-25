/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:56:04 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/25 17:26:03 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	write(1, "rrr", 3);
}

void	ft_rra(t_stack **a, int i)
{
	t_stack	*last;
	t_stack	*temp;

	last = ft_list_last(a);
	temp = last->prev;
	temp->next = NULL;
	last->next = *a;
	last->prev = NULL;
	(*a)->prev = last;
	*a = last;
	if (i == 1)
		write(1, "rra", 3);
}

void	ft_rrb(t_stack **b, int i)
{
	t_stack	*last;
	t_stack	*temp;

	last = ft_list_last(b);
	temp = last->prev;
	temp->next = NULL;
	last->next = *b;
	last->prev = NULL;
	(*b)->prev = last;
	*b = last;
	if (i == 1)
		write(1, "rrb", 3);
}
