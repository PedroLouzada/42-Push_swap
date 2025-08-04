/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:20:02 by pbongiov          #+#    #+#             */
/*   Updated: 2025/07/16 23:34:29 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_stack *stack)
{
	long int	t;
	int			i;

	if (!stack || !stack->head || !stack->head->next)
		return (-1);
	t = stack->head->content;
	i = stack->head->index;
	stack->head->content = stack->head->next->content;
	stack->head->index = stack->head->next->index;
	stack->head->next->content = t;
	stack->head->next->index = i;
	return (0);
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
