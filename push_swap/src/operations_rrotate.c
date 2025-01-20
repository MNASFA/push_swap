/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:55:57 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/20 19:36:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *a)
{
	t_node	*prev;
	t_node	*current;
	
	if (a->size < 2)
		return ;
	current = a->top;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	if (prev)
		prev->next = NULL;
	current->next = a->top;
	a->top = current;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	rra(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rra(b);
	write(1, "rrr\n", 4);
}
