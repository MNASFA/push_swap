/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:17:58 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/20 18:02:47 by hmnasfa          ###   ########.fr       */
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
	t_node *node;
    t_node *current;

    node = ft_lstnew(content);
    if (!node)
        return;
    if (stack->top == NULL)
        stack->top = node;
    else
    {
        current = stack->top;
        while (current->next != NULL)
            current = current->next;
        current->next = node;
    }
    stack->size++;
}

int	stack_pop(t_stack *stack)
{
	t_node *node;
	int		content;
	
	if (stack->size == 0)
		return -1;
	node = stack->top;
	content = node->content;
	stack->top = node->next;
	free(node);
	stack->size--;
	return (content);
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
