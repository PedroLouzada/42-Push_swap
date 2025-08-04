/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:07:25 by pbongiov          #+#    #+#             */
/*   Updated: 2025/07/19 19:32:55 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = value;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	return (stack);
}

int	add_in_stack(t_stack *stack, char **new, int index)
{
	t_node	*node;

	if (!stack || !new || !new[index])
		return (0);
	no_overflow(ft_atol(new[index]), stack, new);
	node = new_node(ft_atol(new[index]));
	node->next = NULL;
	if (stack->tail)
	{
		node->prev = stack->tail;
		stack->tail->next = node;
		stack->tail = node;
	}
	else
	{
		node->prev = NULL;
		stack->head = node;
		stack->tail = node;
	}
	return (0);
}

void	put_in_head(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->head;
	node->prev = NULL;
	if (stack->head)
		stack->head->prev = node;
	else
		stack->tail = node;
	stack->head = node;
}

int	stack_size(t_stack *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack->head;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
