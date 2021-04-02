/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:53:23 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/22 19:54:17 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pin_1_unit_2(t_stack *stack)
{
	if (stack->rsp->number < stack->rsp->next->number)
	{
		rotate_last(stack);
		rotate_last(stack);
	}
	else
	{
		swap(stack);
		rotate_last(stack);
		rotate_last(stack);
	}
}

void	pin_2_unit_2(t_stack *stack, t_stack *dest)
{
	if (stack->rsp->number < stack->rsp->next->number)
	{
		push_a_to_b(stack, dest);
		rotate_last(dest);
		push_a_to_b(stack, dest);
		rotate_last(dest);
	}
	else
	{
		push_a_to_b(stack, dest);
		push_a_to_b(stack, dest);
		rotate_last(dest);
		rotate_last(dest);
	}
}

void	rotate_last_3(t_stack *stack, t_stack *dest)
{
	if (stack->pin == 1)
	{
		rotate_last(stack);
		rotate_last(stack);
		rotate_last(stack);
	}
	else
	{
		push_a_to_b(stack, dest);
		rotate_last(dest);
		push_a_to_b(stack, dest);
		rotate_last(dest);
		push_a_to_b(stack, dest);
		rotate_last(dest);
	}
}

void	pin_1_unit_3(t_stack *stack, t_stack *dest)
{
	int a;
	int b;
	int c;

	a = stack->rsp->number;
	b = stack->rsp->next->number;
	c = stack->rsp->next->next->number;
	if (a < b && b < c && c > a)
		rotate_last_3(stack, dest);
	else if (a < b && b > c && a < c)
		pin_1_a_c_b(stack);
	else if (a > b && b < c && a < c)
		pin_1_b_a_c(stack);
	else if (a < b && b > c && a > c)
		pin_1_b_c_a(stack, dest);
	else if (a > b && b < c && a > c)
		pin_1_c_a_b(stack);
	else if (a > b && b > c && a > c)
		pin_1_c_b_a(stack, dest);
}

void	pin_2_unit_3(t_stack *stack, t_stack *dest)
{
	int a;
	int b;
	int c;

	a = stack->rsp->number;
	b = stack->rsp->next->number;
	c = stack->rsp->next->next->number;
	if (a < b && b < c && c > a)
		rotate_last_3(stack, dest);
	else if (a < b && b > c && a < c)
		pin_2_a_c_b(stack, dest);
	else if (a > b && b < c && a < c)
		pin_2_b_a_c(stack, dest);
	else if (a < b && b > c && a > c)
		pin_2_b_c_a(stack, dest);
	else if (a > b && b < c && a > c)
		pin_2_c_a_b(stack, dest);
	else if (a > b && b > c && a > c)
		pin_2_c_b_a(stack, dest);
}
