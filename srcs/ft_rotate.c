/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:29:58 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/02 17:28:15 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a, 0);
	ft_rb(b, 0);
	write (1, "rr\n", 3);
}

void	ft_ra(t_stack **a, int i)
{
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	last = ft_list_last(a);
	if (!last || !last->prev)
		return ;
	last->next = *a;
	(*a)->next->prev = NULL;
	*a = (*a)->next;
	last->next->prev = last;
	last->next->next = NULL;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int i)
{
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	last = ft_list_last(b);
	if (!last || !last->prev)
		return ;
	last->next = *b;
	(*b)->next->prev = NULL;
	*b = (*b)->next;
	last->next->prev = last;
	last->next->next = NULL;
	if (i == 1)
		write(1, "rb\n", 3);
}
