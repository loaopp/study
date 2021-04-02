/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:15:04 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/23 16:19:52 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_stack
{
	t_list	*rsp;
	t_list	*list;
	int		pin;
	int		roll;
}				t_stack;

void			push_swap(t_stack *st, t_stack *st2);
void			push(t_stack *stack, t_list *new);
t_list			*pop(t_stack *stack);
void			swap(t_stack *a);
void			rotate(t_stack *a);
void			reverse_rotate(t_stack *a);
int				get_stack_size(t_list *lst);
t_list			*last_pop(t_stack *lst);
t_list			*get_rbp();
t_list			*get_base();
t_list			*mini_last(t_list *lst);
void			push_last(t_stack *st, t_list *new);
int				mini_len(t_stack *st);
int				get_stack_mid(t_stack *st);
int				get_sort_mid(int *arr, int size);
void			divide_stack(t_stack *a, t_stack *b);
bool			check_roll_back(t_stack *a, int b);
void			roll_back(t_stack *a, int count);
void			push_a_to_b(t_stack *a, t_stack *b);
bool			check_rbp(t_stack *a);
void			select_a_or_b(t_stack *st, t_stack *st2,
		t_stack **src, t_stack **dest);
void			a_st_b_st2(t_stack *st, t_stack *st2,
		t_stack **src, t_stack **dest);
void			pin_1_unit_2(t_stack *stack);
void			pin_2_unit_2(t_stack *stack, t_stack *dest);
void			pin_1_unit_3(t_stack *stack, t_stack *dest);
void			pin_2_unit_3(t_stack *stack, t_stack *dest);
void			pin_1_a_c_b(t_stack *stack);
void			pin_1_b_a_c(t_stack *stack);
void			pin_1_c_a_b(t_stack *stack);
void			pin_1_c_b_a(t_stack *stack, t_stack *dest);
void			pin_1_b_c_a(t_stack *stack, t_stack *dest);
void			pin_2_a_c_b(t_stack *stack, t_stack *dest);
void			pin_2_b_a_c(t_stack *stack, t_stack *dest);
void			pin_2_c_a_b(t_stack *stack, t_stack *dest);
void			pin_2_c_b_a(t_stack *stack, t_stack *dest);
void			pin_2_b_c_a(t_stack *stack, t_stack *dest);
void			sort_stack(t_stack *srcs, t_stack *dest);
void			rotate_last(t_stack *st);
void			print_list(t_stack *st);
void			push_swap2(t_stack *st, t_stack *st2);
void			len_2(t_stack *st);
void			len_3(t_stack *st);
void			send_a_to_b(t_stack *a, t_stack *b, int mid, int len);
void			len_6(t_stack *st, t_stack *st2, int len);
int				parse_number(int argc, char **argv, t_stack *st);
int				do_checker(t_stack *st, t_stack *st2);
int				check_sort(t_stack *st, t_stack *st2);
void			free_function(t_stack *st, t_stack *st2);
void			norm_by_pass2(char *line, t_stack *st, t_stack *st2);
void			set_struct(t_stack *st, int pin, int k);
int				check_sort2(t_stack *st);
int				check_instruction(char *line);
#endif
