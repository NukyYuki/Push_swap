/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:29:58 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/26 14:46:03 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	write (1, "rr", 2);
}

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
