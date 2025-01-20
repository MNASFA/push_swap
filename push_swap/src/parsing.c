/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:37:41 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/19 11:50:14 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int has_duplicates(t_stack *a, int value)
{
	t_node *current;
	
	current = a->top;
	while (current)
	{
		if (current->content == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int parse_args(t_stack *a, int argc, char **argv)
{
	long long	value;
	int		i;
	int		j;
	char	**split;
	t_node	*new_node;
	
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], " 	");
		if (!split)
			return (0);
		
		j = 0;
		while (split[j])
		{
			value = ft_atoi(split[j]);
			if (!is_valid_number(split[j]) || value < -2147483648 ||
				 value > 2147483647 || has_duplicates(a, (int) value))
				return (ft_putstr_fd("Error\n", 2), free_split(split), 0);
			new_node = ft_lstnew(((int)value));
			if (!new_node)
				return (free_split(split), 0);
			stack_push(a, new_node->content);
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}
