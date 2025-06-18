/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:40:30 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/18 17:49:34 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"

int	ft_valid_numbers(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (ac == 2)
	{
		while ((av[1][i] >= '0' && av[1][i] <= '9') || av[1][i] == ' '
					|| av[1][i] == '+' || av[1][i] == '-')
			i++;
		if (av[1][i] == '\0')
			return (1);
		else
			return (0);
	}
	else
	{
		while (j < ac)
		{
			i = 0;
			while ((av[j][i] >= '0' && av[j][i] <= '9') || av[j][i] == ' '
						|| av[j][i] == '+' || av[j][i] == '-')
				i++;
			if (av[j][i] == '\0')
				j++;
			else
				return (0);
		}
		return (1);
	}
}

int	ft_valid_list(
