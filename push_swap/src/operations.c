/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:38:38 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/15 19:45:33 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include "../push_swap.h"

// Swap the first two elements of a stack
void	sa(t_stack *a)
{
	int tmp;
	
	if (a->size < 2)
		return;
	tmp = a->top->content;
	a->top->content = a->top->next->content;
	a->top->next->content = tmp;
}

void	sb(t_stack *b)
{
	sa(b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

//Push Operations
void	pa(t_stack *a, t_stack *b)
{
	int	content;
	
	if (b->size == 0)
		return ;
	content = stack_pop(b);
	stack_push (a, content);
}

void	pb(t_stack *b, t_stack *a)
{
	pa(b, a);
}
