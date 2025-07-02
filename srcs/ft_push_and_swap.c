/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_and_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:19:54 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/02 12:06:18 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a)
		return ;
	if (!*b)
	{
		*b = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		(*b)->next = NULL;
	}
	else
	{
		temp = *b;
		*b = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		(*b)->next = temp;
		if (!temp->prev)
			(*b)->prev = NULL;
		temp->prev = (*b);
	}
	write(1, "pb\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return ;
	if (!*a)
	{
		*a = *b;
		*b = (*b)->next;
		(*b)->prev = NULL;
		(*a)->next = NULL;
	}
	else
	{
		temp = *a;
		*a = *b;
		if ((*b)->next)
		{
			*b = (*b)->next;
			(*b)->prev = NULL;
		}
		else
			*b = NULL;
		(*a)->next = temp;
		temp->prev = (*a);
		(*a)->prev = NULL;
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
