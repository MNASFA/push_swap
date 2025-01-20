/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:54:27 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/20 20:53:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	content;
	
	if (b->size == 0)
		return ;
	content = stack_pop(b);
	stack_push (a, content);
	write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	pa(b, a);
	write(1, "pb\n", 3);
}