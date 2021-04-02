/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 23:40:35 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/27 23:40:41 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_last(t_stack *st)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = ft_lstlast(st->list);
	tmp2 = st->list;
	st->list = st->rsp->next;
	st->rsp = st->list;
	tmp2->next = tmp->next;
	tmp->next = tmp2;
	if (st->pin == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

int		check_sort2(t_stack *st)
{
	int		tmp;
	t_list	*tmp2;

	tmp = st->list->number;
	tmp2 = st->list->next;
	while (tmp2)
	{
		if (tmp2->number <= tmp && tmp2->status != 2)
			return (0);
		tmp = tmp2->number;
		tmp2 = tmp2->next;
	}
	return (1);
}

int		check_instruction(char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		return (1);
	else if (ft_strcmp(line, "rb") == 0)
		return (1);
	else if (ft_strcmp(line, "pa") == 0)
		return (1);
	else if (ft_strcmp(line, "pb") == 0)
		return (1);
	else if (ft_strcmp(line, "rra") == 0)
		return (1);
	else if (ft_strcmp(line, "rrb") == 0)
		return (1);
	else if (ft_strcmp(line, "sa") == 0)
		return (1);
	else if (ft_strcmp(line, "sb") == 0)
		return (1);
	else if (ft_strcmp(line, "rr") == 0)
		return (1);
	else if (ft_strcmp(line, "rrr") == 0)
		return (1);
	return (0);
}
