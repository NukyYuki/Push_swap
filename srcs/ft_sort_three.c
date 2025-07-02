/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:14:42 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/02 17:36:43 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(t_stack **a)
{
	t_stack	*max_node;

	max_node = NULL;
	max_node = node_max(*a);
	if (*a == max_node)
		ft_ra(a, 1);
	else if ((*a)->next == max_node)
		ft_rra(a, 1);
	if ((*a)->content > (*a)->next->content)
		ft_sa(a, 1);
}
