/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_down_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:11:20 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/23 16:13:44 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	len_2(t_stack *st)
{
	int a;
	int b;

	a = st->rsp->number;
	b = st->rsp->next->number;
	if (a > b)
		swap(st);
}

void	len_3(t_stack *st)
{
	int a;
	int b;
	int c;

	a = st->rsp->number;
	b = st->rsp->next->number;
	c = st->rsp->next->next->number;
	if (a < b && b > c && a < c)
	{
		swap(st);
		rotate(st);
	}
	else if (a > b && b < c && a < c)
		swap(st);
	else if (a < b && b > c && a > c)
		reverse_rotate(st);
	else if (a > b && b < c && a > c)
		rotate(st);
	else if (a > b && b > c && a > c)
	{
		swap(st);
		reverse_rotate(st);
	}
}

void	norm_by_pass(t_stack *st, t_stack *st2)
{
	int len;

	if (st->rsp->status == 2)
		free(pop(st));
	len = mini_len(st);
	if (len == 2)
		len_2(st);
	else if (len == 3)
		len_3(st);
	len = mini_len(st2);
	if (len == 2)
		len_2(st2);
	else if (len == 3)
		len_3(st2);
}

void	merge_a_b(t_stack *st, t_stack *st2)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = st2->list;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (tmp->status == 2)
			break ;
		if (st->rsp->number < tmp->number)
		{
			push_a_to_b(st2, st);
			swap(st);
		}
		else
			push_a_to_b(st2, st);
		tmp = tmp2;
	}
}

void	len_6(t_stack *st, t_stack *st2, int len)
{
	int		mid;
	t_list	*tmp;
	t_list	*tmp2;

	mid = get_stack_mid(st);
	tmp = st->list;
	while (len > 0)
	{
		tmp2 = tmp->next;
		if (tmp->number < mid)
		{
			push_a_to_b(st, st2);
		}
		else
			rotate(st);
		tmp = tmp2;
		len--;
	}
	norm_by_pass(st, st2);
	merge_a_b(st, st2);
}
