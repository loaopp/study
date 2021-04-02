/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:56:05 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/27 23:40:17 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <time.h>

int		mini_len(t_stack *st)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = st->list;
	while (tmp)
	{
		if (tmp->status != 0)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	push_last(t_stack *st, t_list *new)
{
	t_list *tmp;

	if (st->list == NULL)
	{
		st->list = new;
		tmp = 0;
	}
	else
	{
		tmp = mini_last(st->list);
		new->next = tmp->next;
		tmp->next = new;
	}
}

int		parse_number(int argc, char **argv, t_stack *st)
{
	int		number;
	t_list	*stack;

	argc = argc - 1;
	while (argc >= 1)
	{
		number = ft_atoi(argv[argc]);
		if (number == -1 && ft_strcmp(argv[argc], "-1") != 0)
			return (-1);
		if (number == 0 && ft_strcmp(argv[argc], "0") != 0)
			return (-1);
		stack = ft_lstnew(number);
		push(st, stack);
		argc--;
	}
	st->list = stack;
	return (1);
}

bool	check_duplicate(int b, t_stack *st)
{
	t_list *tmp;

	tmp = st->list;
	while (tmp)
	{
		if (tmp->number == b)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	set_struct(t_stack *st, int pin, int k)
{
	if (k == 1)
	{
		st->list = 0;
		st->pin = pin;
		st->roll = 0;
		st->rsp = 0;
		push(st, get_rbp());
	}
	else
	{
		st->list = 0;
		st->pin = pin;
		st->roll = 0;
		st->rsp = 0;
	}
}
