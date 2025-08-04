/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:47:23 by pbongiov          #+#    #+#             */
/*   Updated: 2025/07/19 19:45:36 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long int	ft_atol(const char *str)
{
	int				i;
	int				sign;
	long long int	n;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

int	stack_sorted(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	if (!temp)
	{
		free_stack(stack);
		exit(1);
	}
	while (temp->next)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	create_stack(t_stack *stack, int ac, char *av[])
{
	int		i;
	int		j;
	char	**new;

	i = 1;
	while (i < ac)
	{
		j = 0;
		new = ft_split(av[i], ' ');
		if (!new || new[0] == NULL)
			error_n_exit(stack, new);
		while (new[j])
		{
			if (is_number(new[j]) == -1)
				error_n_exit(stack, new);
			else
				add_in_stack(stack, new, j);
			j++;
		}
		ft_free_str(new);
		i++;
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*to_free;

	if (!stack)
	{
		free(stack);
		return ;
	}
	current = stack->head;
	while (current)
	{
		to_free = current;
		current = current->next;
		free(to_free);
	}
	free(stack);
}

void	error_n_exit(t_stack *stack, char **new)
{
	ft_free_str(new);
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}
