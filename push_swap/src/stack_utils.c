/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:17:58 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/15 19:35:12 by hmnasfa          ###   ########.fr       */
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
	
	node = ft_lstnew(content);
	if (!node)
		return ;
	node->next = stack->top;
	stack->top = node;
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