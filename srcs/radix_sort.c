/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:09:27 by pbongiov          #+#    #+#             */
/*   Updated: 2025/07/17 00:18:51 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_index(t_stack *stack_a)
{
	int		value;
	t_node	*node;
	t_node	*compare;

	node = stack_a->head;
	while (node)
	{
		value = 0;
		compare = stack_a->head;
		while (compare)
		{
			if (node->content > compare->content)
				value++;
			compare = compare->next;
		}
		node->index = value;
		node = node->next;
	}
}

static void	sort_3(t_stack *stack_a)
{
	int	first;
	int	second;

	first = stack_a->head->index;
	second = stack_a->head->next->index;
	if (first < second && first < stack_a->tail->index
		&& second > stack_a->tail->index)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first > second && second < stack_a->tail->index
		&& first < stack_a->tail->index)
		sa(stack_a);
	else if (first < second && second > stack_a->tail->index)
		rra(stack_a);
	else if (first > second && second < stack_a->tail->index)
		ra(stack_a);
	else if (first > second && second > stack_a->tail->index)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

static void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	index;

	size = stack_size(stack_a);
	if (stack_size(stack_a) == 2)
	{
		if (stack_a->head->index > stack_a->head->next->index)
			ra(stack_a);
		return ;
	}
	while (stack_size(stack_a) > 3)
	{
		index = stack_a->head->index;
		if ((size == 5 && (index == 0 || index == 1)) || (size == 4
				&& index == 0))
			pa(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_3(stack_a);
	if (stack_b->head && stack_b->head->next
		&& (stack_b->head->content < stack_b->head->next->content))
		sb(stack_b);
	while (stack_size(stack_b) > 0)
		pb(stack_a, stack_b);
}

int	sorting(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	size_a;

	i = 0;
	if (stack_size(stack_a) <= 5)
		return (sort_5(stack_a, stack_b), 1);
	size_a = stack_size(stack_a);
	while (!stack_sorted(stack_a) || stack_size(stack_b) > 0)
	{
		j = size_a;
		while (j-- > 0)
		{
			if (((stack_a->head->index >> i) & 1) == 0)
				pa(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (stack_size(stack_b))
			pb(stack_a, stack_b);
		i++;
	}
	return (1);
}
