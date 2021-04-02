/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:52:14 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/22 19:53:04 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_to_b(t_stack *a, t_stack *b)
{
	push(b, pop(a));
	if (b->pin == 1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	print_list(t_stack *st)
{
	t_list	*tmp;

	tmp = st->list;
	while (tmp)
	{
		if (tmp->status == 0)
			ft_putnbr(tmp->number);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

void	push_swap(t_stack *st, t_stack *st2)
{
	t_stack *src;
	t_stack *dest;

	a_st_b_st2(st, st2, &src, &dest);
	if (mini_len(src) > 3)
	{
		divide_stack(src, dest);
		push_swap(st, st2);
	}
	else
	{
		a_st_b_st2(st, st2, &src, &dest);
		sort_stack(src, dest);
	}
	if (!(st->pin == 1 && st->rsp->status == 2))
		push_swap(st, st2);
}

void	push_swap2(t_stack *st, t_stack *st2)
{
	int len;

	if (check_sort(st, st2) != 1)
	{
		len = mini_len(st);
		if (len <= 3)
		{
			if (len == 2)
				len_2(st);
			if (len == 3)
				len_3(st);
		}
		else if (len <= 5)
		{
			len_6(st, st2, len);
		}
	}
}

void	norm_by_pass2(char *line, t_stack *st, t_stack *st2)
{
	if (ft_strcmp(line, "ra") == 0)
		rotate(st);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(st2);
	else if (ft_strcmp(line, "sa") == 0)
		swap(st);
	else if (ft_strcmp(line, "sb") == 0)
		swap(st2);
	free(line);
}
