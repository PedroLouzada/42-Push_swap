/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:24:02 by pbongiov          #+#    #+#             */
/*   Updated: 2025/07/19 19:39:58 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//============================ STRUCTS ===========================
typedef struct s_node
{
	long int		content;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
}					t_stack;

t_node				*new_node(int value);
t_stack				*new_stack(void);
int					add_in_stack(t_stack *stack, char **new, int index);
void				put_in_head(t_stack *stack, t_node *node);
int					stack_size(t_stack *stack);
int					create_stack(t_stack *stack, int ac, char *av[]);
void				free_stack(t_stack *stack);
//======================= OPERATIONS ============================
//
//================= SWAP ===================
int					swap(t_stack *stack);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
//================= PUSH ===================
int					push(t_stack *give, t_stack *receive);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_b, t_stack *stack_a);
//================ ROTATE ==================
int					rotate(t_stack *stack);
void				ra(t_stack *stack_b);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
//=============== REV.ROTATE ===============
int					reverse_rotate(t_stack *stack);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);

//======================== PARSING ===============================
int					is_number(char *str);
long long int		ft_atol(const char *str);
int					no_overflow(long long int num, t_stack *stack, char **str);
int					is_dup(t_stack *stack_a);
int					parsing(t_stack *stack_a);
char				**ft_split(char const *s, char c);
void				error_n_exit(t_stack *stack, char **new);

//======================== SORTING ===============================
void				check_index(t_stack *stack_a);
int					sorting(t_stack *stack_a, t_stack *stack_b);
int					stack_sorted(t_stack *stack);
void				ft_free_str(char **str);
#endif