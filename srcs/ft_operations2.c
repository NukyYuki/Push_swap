/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:56:04 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/18 14:29:29 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stack **a, int i)
{
	t_stack	*last;
	t_stack	*temp;

	last = ft_list_last(a);
	temp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
	if (i == 1)
		write(1, "ra", 2);
}

void	ft_rb(t_stack **b, int i)
{
	t_stack	*last;
	t_stack	*temp;

	last = ft_list_last(b);
	temp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
	if (i == 1)
		write(1, "rb", 2);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	write (1, "rr", 2);
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
