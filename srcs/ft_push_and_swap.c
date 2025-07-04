/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_and_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:19:54 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/04 11:01:58 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	temp->prev = NULL;
	if (!*b)
	{
		*b = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *b;
		temp->next->prev = temp;
		*b = temp;
	}
	write(1, "pb\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->prev = NULL;
	if (!*a)
	{
		*a = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *a;
		temp->next->prev = temp;
		*a = temp;
	}
	write(1, "pa\n", 3);
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
	if (temp->next)
		temp->next->prev = temp;
	(*a)->next = temp;
	(*a)->prev = NULL;
	if (i == 1)
		write(1, "sa\n", 3);
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
	if (temp->next)
		temp->next->prev = temp;
	(*b)->next = temp;
	(*b)->prev = NULL;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	write(1, "ss\n", 3);
}
