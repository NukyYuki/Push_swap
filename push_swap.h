/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:41:31 by mipinhei          #+#    #+#             */
/*   Updated: 2025/07/04 12:23:27 by mipinhei         ###   ########.fr       */
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
	int					op_cost;
	int					top_stack;
	int					cheapest;
	struct s_list_stack	*target;
	struct s_list_stack	*next;
	struct s_list_stack	*prev;
}	t_stack;

//	list helper
void	ft_stack_init(t_stack **a, int ac, char **av);
t_stack	*ft_list_last(t_stack **head);
void	add_node(t_stack **a, int content);
int		ft_list_size(t_stack *head);
long	ft_atol(char *str);
//	libft
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
//	operation functions
void	ft_sa(t_stack **a, int i);
void	ft_sb(t_stack **b, int i);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
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
void	free_err(t_stack **a, int ac, char **av);
void	ft_free_av(char **av);
//	sorting
int		ft_sort_checker(t_stack *a);
void	ft_sort_three(t_stack **a);
void	ft_sort_stacks(t_stack **a, t_stack **b);
//	turk
void	ft_turk(t_stack **a, t_stack **b);
void	prep_rot_b(t_stack **a, t_stack **b, t_stack *cheapest);
void	prep_rot_a(t_stack **a, t_stack **b, t_stack *cheapest);
void	prep_push_to_b(t_stack **stack, t_stack *cheapest, int check);
void	ft_rushb(t_stack **a, t_stack **b);
void	ft_rusha(t_stack **a, t_stack **b);
//	sort prep
t_stack	*node_min(t_stack *stack);
t_stack	*node_max(t_stack *stack);
t_stack	*ft_cheapest_node(t_stack *stack);
void	find_cheapest(t_stack *stack);
void	prep_stacks(t_stack **a, t_stack **b);
void	prep_stack_a(t_stack **a, t_stack **b);
void	prep_stack_b(t_stack **a, t_stack **b);
void	setup_push(t_stack **a, t_stack *b, int check);
void	ft_indexing(t_stack *stack);
void	operations_cost_a(t_stack *a, t_stack *b);
void	operations_cost_b(t_stack *a, t_stack *b);
void	a_target(t_stack *a, t_stack *b);
void	b_target(t_stack *a, t_stack *b);
void	check_top(t_stack **a);
int		valid_node(t_stack *stack, int content);

#endif
