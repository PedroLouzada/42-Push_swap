/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:42:54 by pbongiov          #+#    #+#             */
/*   Updated: 2025/07/16 23:32:43 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push(t_stack *give, t_stack *receive)
{
	t_node	*node;

	if (!give || !give->head || !receive)
		return (-1);
	node = give->head;
	give->head = node->next;
	if (give->head)
		give->head->prev = NULL;
	else
		give->tail = NULL;
	node->next = receive->head;
	node->prev = NULL;
	if (receive->head)
		receive->head->prev = node;
	else
		receive->tail = node;
	receive->head = node;
	return (0);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}
