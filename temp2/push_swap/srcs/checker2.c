/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:06:50 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/23 16:13:17 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *st, t_stack *st2)
{
	rotate(st);
	rotate(st2);
}

void	rrr(t_stack *st, t_stack *st2)
{
	reverse_rotate(st);
	reverse_rotate(st2);
}

int		check_sort(t_stack *st, t_stack *st2)
{
	int		tmp;
	t_list	*tmp2;

	tmp = st->list->number;
	tmp2 = st->list->next;
	if (st2->rsp != 0)
		if (st2->rsp->status != 2)
			return (0);
	while (tmp2)
	{
		if (tmp2->number <= tmp && tmp2->status != 2)
			return (0);
		tmp = tmp2->number;
		tmp2 = tmp2->next;
	}
	return (1);
}

int		do_checker(t_stack *st, t_stack *st2)
{
	char *line;

	line = 0;
	while (get_next_line(0, &line) != 0)
	{
		if (check_instruction(line) == 0)
			return (3);
		if (ft_strcmp(line, "rra") == 0)
			reverse_rotate(st);
		else if (ft_strcmp(line, "rrb") == 0)
			reverse_rotate(st2);
		else if (ft_strcmp(line, "rr") == 0)
			rr(st, st2);
		else if (ft_strcmp(line, "rrr") == 0)
			rrr(st, st2);
		else if (ft_strcmp(line, "pa") == 0)
			push_a_to_b(st2, st);
		else if (ft_strcmp(line, "pb") == 0)
			push_a_to_b(st, st2);
		norm_by_pass2(line, st, st2);
	}
	return (1);
}

void	free_function(t_stack *st, t_stack *st2)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = st->list;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	tmp = st2->list;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	free(st);
	free(st2);
}
