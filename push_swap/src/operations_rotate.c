/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:55:17 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/20 14:30:52 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a)
{
	int		content;
	t_node	*new_node;
	t_node	*current;
	
	if (a->size < 2)
		return ;
	content = stack_pop(a);
	new_node = ft_lstnew(content);
	if (!new_node)
		return ;
	current = a->top;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	a->size++;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	ra(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	ra(b);
	write(1, "rr\n", 3);
}