/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:38:38 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/20 19:36:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a)
{
	int tmp;
	
	if (a->size < 2)
		return;
	tmp = a->top->content;
	a->top->content = a->top->next->content;
	a->top->next->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	sa(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
