/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:57:01 by pbongiov          #+#    #+#             */
/*   Updated: 2025/07/19 19:11:39 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = new_stack();
	create_stack(stack_a, ac, av);
	parsing(stack_a);
	check_index(stack_a);
	if (stack_sorted(stack_a) == 1)
	{
		free_stack(stack_a);
		return (0);
	}
	stack_b = new_stack();
	sorting(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
