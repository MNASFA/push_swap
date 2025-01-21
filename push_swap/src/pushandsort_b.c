/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushandsort_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:23:55 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/21 14:45:07 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_indexes(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		i;
	
	if (!a || !a->top)
		return ;
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

int find_position(t_stack *b)
{
	t_node *current;
	int max;
	int position;

	max = INT_MIN;
	position = 0;
	current = b->top;
	while (b->top)
	{
		if (b->top->content >= max)
			max = b->top->content;
		b->top = b->top->next;
	}
	while (current && current->content != max)
	{
		current = current->next;
		position++;
	}
	return (position);
}

int	chunk_size(int size)
{
	if (size > 100)
		return (33);
	return (16);
}

void	push_to_stack_b(t_stack *a, t_stack *b, int i)
{
	t_node *tmp;
	int size_chunk;

	if (!a || !a->top)
		return ;
	size_chunk = chunk_size(a->size);
	while (a->top)
	{
		tmp = a->top;
		if (tmp->index <= i)
		{
			pb(b, a);
			i++;
		}
		else if (tmp->index < (i + size_chunk))
		{
			pb(b, a);
			rb(b);
			i++;
		}
	}
}

void	push_to_stack_a(t_stack *a, t_stack *b)
{
	int size;
	int position;

	size = b->size;
	while (size)
	{
		position = find_position(b);
		if (position <= size / 2)
		{
			while (position--)
				rb(b);
		}
		else
		{
			while (position++ != size)
				rrb(b);
		}
		pa(a, b);
		size--;
	}
}
