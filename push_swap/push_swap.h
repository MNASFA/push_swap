/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:02:16 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/21 13:37:05 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

//node structure 
typedef struct s_node
{
	int content;
	int index;
	struct s_node *next;
	
}	t_node;

//stack structure
typedef struct s_stack
{
	t_node *top;
	int	size;
}	t_stack;

t_node		*ft_lstnew(int content);
void		stack_push(t_stack *stack, int content);
int			stack_pop(t_stack *stack);
void		free_stack(t_stack *stack);


long long	ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *str);
char		**ft_split(char *s, char *delims);
	


//Operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

int		parse_args(t_stack *a, int argc, char **argv);
int		is_sorted(t_stack *a);
void	sort_three_elements(t_stack *a);
void	sort_two_elements(t_stack *a);
// void	sort_medium_stack(t_stack *a, t_stack *b);
void	assign_indexes(t_stack *a);
void sort_five_elements(t_stack *a, t_stack *b);
void	sort_four_elements(t_stack *a, t_stack *b);
void print_stack(t_stack *stack);
int find_largest(t_stack *a);
int find_smallest(t_stack *a);
void	push_to_stack_b(t_stack *a, t_stack *b, int i);
void	push_to_stack_a(t_stack *a, t_stack *b);



#endif