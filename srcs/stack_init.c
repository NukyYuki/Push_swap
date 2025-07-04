/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:42:22 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/04 11:54:17 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stack_init(t_stack **a, int ac, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (ft_valid_numbers(av[i]) == 1)
			free_err(a, ac, av);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_err(a, ac, av);
		if (ft_valid_list(*a, n) == 1)
			free_err(a, ac, av);
		add_node(a, (int)n);
		i++;
	}
}

long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	add_node(t_stack **a, int content)
{
	t_stack	*new;
	t_stack	*previous;

	if (!a)
		return ;
	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->next = NULL;
	new->content = content;
	if (!*a)
	{
		*a = new;
		new->prev = NULL;
	}
	else
	{
		previous = ft_list_last(a);
		previous->next = new;
		new->prev = previous;
	}
}
