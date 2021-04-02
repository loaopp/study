/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 20:43:02 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/22 20:44:07 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, t_list *new)
{
	new->next = stack->list;
	stack->list = new;
	stack->rsp = new;
}

t_list	*pop(t_stack *stack)
{
	t_list *tmp;

	tmp = 0;
	if (stack->rsp != 0)
	{
		tmp = stack->rsp;
		stack->rsp = stack->rsp->next;
		tmp->next = 0;
		stack->list = stack->rsp;
	}
	return (tmp);
}

void	swap(t_stack *st)
{
	t_list *tmp;
	t_list *tmp2;

	if (st->rsp == 0)
		return ;
	tmp = st->list;
	tmp2 = st->list->next;
	tmp->next = st->list->next->next;
	st->rsp = tmp2;
	st->list = st->rsp;
	tmp2->next = tmp;
	if (st->pin == 1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	rotate(t_stack *st)
{
	t_list *tmp;
	t_list *tmp2;

	if (st->rsp == 0)
		return ;
	tmp = ft_lstlast(st->list);
	tmp2 = st->list;
	st->list = st->rsp->next;
	st->rsp = st->list;
	tmp2->next = tmp->next;
	tmp->next = tmp2;
	if (st->pin == 1)
		write(1, "ra\n", 3);
	else if (st->pin == 2)
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack *st)
{
	t_list *tmp;

	tmp = last_pop(st);
	push(st, tmp);
	if (st->pin == 1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
