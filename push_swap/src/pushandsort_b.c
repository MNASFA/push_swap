/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushandsort_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:23:55 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/20 10:24:41 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_indexes(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		i;
	
	current = a->top;
	while (current)
	{
		i = 0;
		compare = a->top;
		while (compare)
		{
			if (current->content > compare->content)
				i++;
			compare = compare->next;
		}
		current->index = i;
		current = current->next;
	}
}
