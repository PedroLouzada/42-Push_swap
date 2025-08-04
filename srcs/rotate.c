/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:19:20 by pbongiov          #+#    #+#             */
/*   Updated: 2025/07/16 23:34:09 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_stack *stack)
{
	int		value;
	int		index;
	t_node	*temp;

	if (!stack || !stack->head || !stack->head->next)
		return (-1);
	temp = stack->head;
	value = stack->head->content;
	index = stack->head->index;
	while (temp->next)
	{
		temp->content = temp->next->content;
		temp->index = temp->next->index;
		temp = temp->next;
	}
	stack->tail->content = value;
	stack->tail->index = index;
	return (0);
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
