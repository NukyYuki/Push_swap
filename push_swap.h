/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:41:31 by mipinhei          #+#    #+#             */
/*   Updated: 2025/06/18 15:30:41 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list_stack
{
	int					content;
	int					index;
	int					op_nb;
	struct s_list_stack	*target;
	struct s_list_stack	*next;
	struct s_list_stack	*prev;
}	t_stack;

//	list helper
t_stack	ft_list_last(t_stack **head);
void	add_node(t_stack **a, int content);
char	**ft_split(char const *s, char c);
int		ft_list_size(t_stack **head);
//	operation functions
void	ft_sa(t_stack **a, int i);
void	ft_sb(t_stack **b, int i);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **b, t_stack **b);
void	ft_ra(t_stack **a, int i);
void	ft_rb(t_stack **b, int i);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rra(t_stack **a, int i);
void	ft_rrb(t_stack **b, int i);
void	ft_rrr(t_stack **a, t_stack **b);
//	error handler
int		ft_valid_numbers(char *av);
int		ft_valid_list(t_stack *a, int n);
void	ft_free_list(t_stack **a);
void	free_err(t_stack **a);
//	sorting
t_stack	node_max(t_stack *stack);
int		ft_sort_checker(t_stack *a);
void	ft_sort_three(t_stack **a);

#endif
