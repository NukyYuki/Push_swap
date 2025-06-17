/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:19:54 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/17 17:54:29 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(stack **a, stack **b)
{
	stack	*temp;

	if (!*a)
		return ;
	temp = *b;
	*a = *b;
	*a = *a->next;
	*b->next = temp;
	write(1, "pb", 2);
}

void	ft_pa(stack **a, stack **b)
{
	stack	*temp;

	if (!*b)
		return ;
	temp = *a;
	*b = *a;
	*b = *b->next;
	*a->next = temp;
	write(1, "pa", 2);
}
