/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:52:21 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/21 15:02:05 by hmnasfa          ###   ########.fr       */
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

// int main(int argc, char **argv)
// {
// 	t_stack a;
// 	t_stack b;
	
// 	if (argc < 2)
// 	{
// 		ft_putstr_fd("Error\n" , 2);
// 		return (1);
// 	}
	
// 	a.top = NULL;
// 	a.size = 0;
// 	b.top = NULL;
// 	b.size = 0;
// 	// Parse arguments and populate Stack A
//     if (!parse_args(&a, argc, argv))
//         return (1);
//     // Print the initial state of Stack A
//     printf("Before sorting:\n");
//     print_stack(&a);

//     if (is_sorted(&a))
//         return (0);
    
//     if (a.size == 2)
//         sort_two_elements(&a);
//     else if (a.size == 3)
//         sort_three_elements(&a);
//     else if (a.size == 4)
//         sort_four_elements(&a, &b);
//     else if (a.size == 5)
//     {
//         sort_five_elements(&a, &b);
//     }
//     else
//     {
//         assign_indexes(&a);
//         push_to_stack_b(&a, &b, 0);
//         push_to_stack_a(&a, &b);
//     }
    
//     printf("\nAfter sorting:\n");
//     print_stack(&a);
//     // Free the stacks
//     free_stack(&a);
//     free_stack(&b);
// 	return (0);
// }

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }

    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;

    printf("Parsing arguments...\n");
    if (!parse_args(&a, argc, argv))
    {
        ft_putstr_fd("Error: Failed to parse arguments.\n", 2);
        return (1);
    }

    printf("Before sorting:\n");
    assign_indexes(&a);
    print_stack(&a);

    if (is_sorted(&a))
    {
        printf("Stack is already sorted.\n");
        free_stack(&a);
        free_stack(&b);
        return (0);
    }

    printf("Sorting...\n");
    if (a.size == 2)
    {
        printf("Sorting 2 elements...\n");
        sort_two_elements(&a);
    }
    else if (a.size == 3)
    {
        printf("Sorting 3 elements...\n");
        sort_three_elements(&a);
    }
    else if (a.size == 4)
    {
        printf("Sorting 4 elements...\n");
        sort_four_elements(&a, &b);
    }
    else if (a.size == 5)
    {
        printf("Sorting 5 elements...\n");
        sort_five_elements(&a, &b);
    }
    else
    {
        printf("Sorting more than 5 elements...\n");
        printf("Pushing elements to stack B...\n");
        
        printf("Before sorting:\n");
        print_stack(&a);
        push_to_stack_b(&a, &b, 0);
        // printf("Pushing elements back to stack A...\n");
        //push_to_stack_a(&a, &b);
    }

    printf("\nAfter sorting:\n");
    print_stack(&a);
    
    printf("\nStack B:\n");
    print_stack(&b);

    printf("Freeing stacks...\n");
    free_stack(&a);
    free_stack(&b);

    printf("Done.\n");
    return (0);
}