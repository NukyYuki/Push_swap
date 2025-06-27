/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:00:43 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/27 17:11:32 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_list_last(t_stack **head)
{
	t_stack	*index;

	index = NULL;
	if (!*head)
		return (NULL);
	index = *head;
	while (index->next)
		index = index->next;
	return (index);
}

int	ft_list_size(t_stack *head)
{
	int	i;

	i = 1;
	if (!head)
		return (0);
	while (head->next)
	{
		head = head->next;
		i++;
	}
	return (i);
}
