/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:19:54 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/25 17:28:35 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *b;
	*a = *b;
	*a = (*a)->next;
	(*b)->next = temp;
	write(1, "pb", 2);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *a;
	*b = *a;
	*b = (*b)->next;
	(*a)->next = temp;
	write(1, "pa", 2);
}

void	ft_sa(t_stack **a, int i)
{
	t_stack	*temp;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	temp->prev = *a;
	(*a)->next = temp;
	(*a)->prev = NULL;
	if (i == 1)
		write(1, "sa", 2);
}

void	ft_sb(t_stack **b, int i)
{
	t_stack		*temp;

	if (!*b || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	temp->prev = *b;
	(*b)->next = temp;
	(*b)->prev = NULL;
	if (i == 1)
		write(1, "sb", 2);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	write(1, "ss", 2);
}
