/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:40:30 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/26 13:05:32 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_valid_numbers(char *av)
{
	if (!((*av >= '0' && *av <= '9') || *av == '+' || *av == '-'))
		return (1);
	if ((!(*av >= '0' && *av <= '9') || *av == '+' || *av == '-'))
		return (1);
	while (*++av)
	{
		if (!(*av >= '0' && *av <= '9'))
			return (1);
	}
	return (0);
}

int	ft_valid_list(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->content == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_free_list(t_stack **a)
{
	t_stack	*temp;
	t_stack	*current;

	if (!a)
		return ;
	current = *a;
	while (current)
	{
		temp = current->next;
		current->content = 0;
		free(current);
		current = temp;
	}
	*a = NULL;
}

void	free_err(t_stack **a)
{
	ft_free_list(a);
	write(1, "Error\n", 6);
	exit(1);
}
