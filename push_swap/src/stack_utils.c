/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:17:58 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/21 15:32:51 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node *ft_lstnew(int content)
{
	t_node	*node;
	
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	stack_push(t_stack *stack, int content)
{
	t_node	*node;
	t_node	*tmp;

	node = ft_lstnew(content);
	if (!node)
		return;
	if (stack->top == NULL)
		stack->top = node;
	else
	{
		tmp = stack->top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	stack->size++;
}


t_node	stack_pop(t_stack *stack)
{
	t_node *node;
	
	if (stack->size == 0)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	stack->size--;
	return (node);
}

void free_stack(t_stack *stack)
{
	while (stack->size > 0)
		stack_pop(stack);	
}

int is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || !a->top)
		return (1);
	current = a->top;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
