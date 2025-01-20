/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:10:29 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/20 18:32:56 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_two_elements(t_stack *a)
{
	int	top;
	int	bottom;

	top = a->top->content;
	bottom = a->top->next->content;
	if (top > bottom)
		sa(a);
}

void sort_three_elements(t_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = a->top->content;
	mid = a->top->next->content;
	bottom = a->top->next->next->content;
	if (top > mid && mid < bottom && top < bottom)
		sa(a);
	else if(top > mid && mid > bottom)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bottom && top > bottom)
		ra(a);
	else if (top < mid && mid > bottom && top < bottom)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bottom && top > bottom)
		rra(a);
}

int find_smallest(t_stack *a)
{
	t_node *current;
	int smallest;
	
	current = a->top;
	smallest = current->content;
	while (current)
	{
		if (current->content < smallest)
			smallest = current->content;
		current = current->next;
	}
	return (smallest);
}

int find_second_smallest(t_stack *a)
{
	t_node current;
	int smallest;
	int second_smallest;

	current = a->top;
	second_smallest = 2147483647;
	smallest = find_smallest(a);
	while (current)
	{
		if (current.content > smallest && current.content < second_smallest)
			
	}
	
}

void push_two_smallest_to_b(t_stack *a, t_stack *b)
{
	int smallest1;
	int smallest2;

	if (is_sorted(a))
		return ;
	smallest = a->top->content;
	position = 0;
	current = a->top;
	i = 0;

	while (current)
	{
		if (current->content < smallest)
		{
			smallest = current->content;
			position = i;
		}
		current = current->next;
		i++;
	}
	if (position <= a->size / 2)
	{
		while (position--)
			ra(a);
	}
	else
	{
		while (position++ < a->size)
			rra(a);
	}
	rra(a);
}

void sort_four_elements(t_stack *a)
{
	move_smallest_to_bottom(a);
	sort_three_elements(a);
}

void sort_five_elements(t_stack *a)
{
	if (is_sorted(a))
		return ;
	move_smallest_to_bottom(a);
	move_smallest_to_bottom(a);
	sort_three_elements(a);
}