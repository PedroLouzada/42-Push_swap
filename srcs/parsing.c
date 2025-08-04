/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:44:58 by pbongiov          #+#    #+#             */
/*   Updated: 2025/07/19 19:34:34 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (i != 0 || !(str[1] >= '0' && str[1] <= '9'))
				return (-1);
		}
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

int	no_overflow(long long int num, t_stack *stack, char **str)
{
	if (num > INT_MAX || num < INT_MIN)
	{
		free_stack(stack);
		ft_free_str(str);
		write (2, "Error\n", 6);
		exit(1);
	}
	return (0);
}

int	is_dup(t_stack *stack_a)
{
	t_node	*current;
	t_node	*compare;

	current = stack_a->head;
	while (current->next)
	{
		compare = current->next;
		while (compare)
		{
			if (current->content == compare->content)
				return (-1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

int	parsing(t_stack *stack_a)
{
	t_node	*node;

	node = stack_a->head;
	if (!stack_a)
		return (-1);
	while (node)
	{
		if (is_dup(stack_a) == -1)
		{
			free_stack(stack_a);
			write(2, "Error\n", 6);
			exit (1);
		}
		node = node->next;
	}
	return (0);
}
