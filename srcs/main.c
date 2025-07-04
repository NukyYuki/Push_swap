/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:14:49 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/04 12:19:47 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	ft_sort_stacks(t_stack **a, t_stack **b);

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		ft_stack_init(&a, ac, av);
	}
	else
		ft_stack_init(&a, ac, av + 1);
	while (!ft_sort_checker(a))
	{
		ft_sort_stacks(&a, &b);
	}
	if (ac == 2)
		ft_free_av(av);
	ft_free_list(&a);
	return (0);
}
