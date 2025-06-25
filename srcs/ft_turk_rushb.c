/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_rushb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:51:51 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/25 17:09:13 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rushb(t_stack **a, t_stack **b)
{
	int		stack_size;
	t_stack	*cheapest;

	if (!a || !b)
		return ;
	stack_size = ft_list_size(*a);
	cheapest = *a;
	while (stack_size-- > 3)
	{
		while ((*a)->cheapest
		if (
	}
}
