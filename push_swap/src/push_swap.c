/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:10:29 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/21 10:45:05 by hmnasfa          ###   ########.fr       */
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
	
	if (!a || !a->top)
		return (-1);
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

int find_largest(t_stack *a)
{
	t_node *current;
	int largest;

	if (!a || !a->top)
		return (-1);
	current = a->top;
	largest = current->content;
	while (current)
	{
		if (current->content > largest)
			largest = current->content;
		current = current->next;
	}
	return (largest);
}

void sort_four_elements(t_stack *a, t_stack *b)
{
	int smallest;
	
	smallest = find_smallest(a);
	while (a->top->content != smallest)
		ra(a);
	if (!is_sorted(a))
		pb(b, a);
	sort_three_elements(a);
	pa(a, b);
}

void sort_five_elements(t_stack *a, t_stack *b)
{
	int smallest;
	
	smallest = find_smallest(a);
	while (a->top->content != smallest)
		ra(a);
	if (!is_sorted(a))	
		pb(b, a);
	smallest = find_smallest(a);
	while (a->top->content != smallest)
		ra(a);
	if (!is_sorted(a))
		pb(b, a);
	sort_three_elements(a);
	pa(a, b);
	pa(a, b);
	pa(a, b);
}
