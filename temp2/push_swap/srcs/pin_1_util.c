/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pin_1_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:08:12 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/22 21:08:29 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pin_1_a_c_b(t_stack *stack)
{
	rotate_last(stack);
	swap(stack);
	rotate_last(stack);
	rotate_last(stack);
}

void	pin_1_b_a_c(t_stack *stack)
{
	swap(stack);
	rotate_last(stack);
	rotate_last(stack);
	rotate_last(stack);
}

void	pin_1_b_c_a(t_stack *stack, t_stack *dest)
{
	push_a_to_b(stack, dest);
	swap(stack);
	rotate_last(stack);
	push_a_to_b(dest, stack);
	rotate_last(stack);
	rotate_last(stack);
}

void	pin_1_c_a_b(t_stack *stack)
{
	swap(stack);
	rotate_last(stack);
	swap(stack);
	rotate_last(stack);
	rotate_last(stack);
}

void	pin_1_c_b_a(t_stack *stack, t_stack *dest)
{
	push_a_to_b(stack, dest);
	swap(stack);
	rotate_last(stack);
	rotate_last(stack);
	push_a_to_b(dest, stack);
	rotate_last(stack);
}
