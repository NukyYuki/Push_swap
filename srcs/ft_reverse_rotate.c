/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:56:04 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/27 17:14:53 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	write(1, "rrr\n", 4);
}

void	ft_rra(t_stack **a, int i)
{
	t_stack	*last;
	t_stack	*temp;

	if (!*a || !(*a)->next)
		return ;
	last = ft_list_last(a);
	if (!last || !last->prev)
		return ;
	temp = last->prev;
	temp->next = NULL;
	last->next = *a;
	last->prev = NULL;
	(*a)->prev = last;
	*a = last;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int i)
{
	t_stack	*last;
	t_stack	*temp;

	if (!*b || !(*b)->next)
		return ;
	last = ft_list_last(b);
	if (!last || !last->prev)
		return ;
	temp->next = NULL;
	last->next = *b;
	last->prev = NULL;
	(*b)->prev = last;
	*b = last;
	if (i == 1)
		write(1, "rrb\n", 4);
}
