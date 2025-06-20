/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:14:49 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/18 17:49:45 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	ft_stack_init(&a, av + 1);
	if (!ft_sort_checker(a))
	{
		if (ft_list_size(a) == 2)
			ft_sa(&a, 1);
		else if (ft_list_size(a) == 3)
			ft_sort_three(&a);
		else
			ft_turk(&a, &b);
	}
	ft_free_list(&a);
	return (0);
}
