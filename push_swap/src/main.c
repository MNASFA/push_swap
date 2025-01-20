/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:52:21 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/20 22:04:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current) {
        
        printf("%d | %d\n", current->content, current->index);
        current = current->next;
    }
	printf("\n");
}

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	
	if (argc < 2)
	{
		ft_putstr_fd("Error\n" , 2);
		return (1);
	}
	
	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	// Parse arguments and populate Stack A
    if (!parse_args(&a, argc, argv))
        return (1);
    // Print the initial state of Stack A
    printf("Before sorting:\n");
    assign_indexes(&a);
    print_stack(&a);

    if (is_sorted(&a))
        return (0);
    
    if (a.size == 2)
        sort_two_elements(&a);
    else if (a.size == 3)
        sort_three_elements(&a);
    else if (a.size == 4)
        sort_four_elements(&a, &b);
    else if (a.size == 5)
        sort_five_elements(&a, &b);
    else 
        printf("Not yet !!\n");
    
    printf("\nAfter sorting:\n");
    assign_indexes(&a);
    print_stack(&a);
    // Free the stacks
    free_stack(&a);
    free_stack(&b);
	return (0);
}