/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:00:43 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/18 13:58:03 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_list_last(t_stack **head)
{
	if (!*head)
		return (NULL);
	while (*head->next)
		*head = head->next;
	return (*head);
}

int	ft_list_size(t_stack **head)
{
	int	i;

	i = 0;
	if (!*head)
		return (0);
	while (*head)
	{
		*head = head->next;
		i++;
	}
	return (i);
}
