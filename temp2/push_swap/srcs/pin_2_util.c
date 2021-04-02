/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pin_2_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:10:43 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/22 21:11:10 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pin_2_a_c_b(t_stack *stack, t_stack *dest)
{
	push_a_to_b(stack, dest);
	rotate_last(dest);
	push_a_to_b(stack, dest);
	push_a_to_b(stack, dest);
	rotate_last(dest);
	rotate_last(dest);
}

void	pin_2_b_a_c(t_stack *stack, t_stack *dest)
{
	push_a_to_b(stack, dest);
	push_a_to_b(stack, dest);
	rotate_last(dest);
	rotate_last(dest);
	push_a_to_b(stack, dest);
	rotate_last(dest);
}

void	pin_2_b_c_a(t_stack *stack, t_stack *dest)
{
	swap(stack);
	push_a_to_b(stack, dest);
	push_a_to_b(stack, dest);
	push_a_to_b(stack, dest);
	rotate_last(dest);
	rotate_last(dest);
	rotate_last(dest);
}

void	pin_2_c_a_b(t_stack *stack, t_stack *dest)
{
	push_a_to_b(stack, dest);
	push_a_to_b(stack, dest);
	rotate_last(dest);
	push_a_to_b(stack, dest);
	rotate_last(dest);
	rotate_last(dest);
}

void	pin_2_c_b_a(t_stack *stack, t_stack *dest)
{
	push_a_to_b(stack, dest);
	push_a_to_b(stack, dest);
	push_a_to_b(stack, dest);
	rotate_last(dest);
	rotate_last(dest);
	rotate_last(dest);
}
