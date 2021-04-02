/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:16:47 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/22 21:17:37 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_unit_2(t_stack *src, t_stack *dest)
{
	if (src->pin == 1)
		pin_1_unit_2(src);
	else if (src->pin == 2)
		pin_2_unit_2(src, dest);
}

void	sort_unit_3(t_stack *src, t_stack *dest)
{
	if (src->pin == 1)
		pin_1_unit_3(src, dest);
	else if (src->pin == 2)
		pin_2_unit_3(src, dest);
}

void	sort_stack(t_stack *st, t_stack *st2)
{
	int		len;
	t_stack	*src;
	t_stack	*dest;

	select_a_or_b(st, st2, &src, &dest);
	len = mini_len(src);
	if (len == 2)
		sort_unit_2(src, dest);
	else if (len == 3)
		sort_unit_3(src, dest);
	if (src->rsp->status == 1)
		free(pop(src));
}

void	select_a_or_b(t_stack *st, t_stack *st2, t_stack **src, t_stack **dest)
{
	if (st->rsp->status == 2)
	{
		*src = st2;
		*dest = st;
	}
	else if (st2->rsp->status == 2)
	{
		*src = st;
		*dest = st2;
	}
	else if (st->rsp->number > st2->rsp->number)
	{
		*src = st2;
		*dest = st;
	}
	else if (st->rsp->number < st2->rsp->number)
	{
		*src = st;
		*dest = st2;
	}
}

void	a_st_b_st2(t_stack *st, t_stack *st2, t_stack **src, t_stack **dest)
{
	if (st2->rsp->status != 0)
	{
		*src = st;
		*dest = st2;
	}
	else if (st->rsp->status != 0)
	{
		*src = st2;
		*dest = st;
	}
	else if (st->rsp->number > st2->rsp->number)
	{
		*src = st2;
		*dest = st;
	}
	else if (st->rsp->number < st2->rsp->number)
	{
		*src = st;
		*dest = st2;
	}
}
