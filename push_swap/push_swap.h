/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:02:16 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/15 16:20:36 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

//node structure 
typedef struct s_node
{
	int content;
	struct s_node *next;
	
}	t_node;

//stack structure
typedef struct s_stack
{
	t_node *top;
	int	size;
}	t_stack;


#endif