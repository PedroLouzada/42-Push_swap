/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:34:49 by pbongiov          #+#    #+#             */
/*   Updated: 2025/07/16 23:33:52 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	reverse_rotate(t_stack *stack)
{
	int		value;
	int		index;
	t_node	*temp;

	if (!stack || !stack->head || !stack->head->next)
		return (-1);
	temp = stack->tail;
	value = stack->tail->content;
	index = stack->tail->index;
	while (temp->prev)
	{
		temp->content = temp->prev->content;
		temp->index = temp->prev->index;
		temp = temp->prev;
	}
	stack->head->content = value;
	stack->head->index = index;
	return (0);
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rra\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
