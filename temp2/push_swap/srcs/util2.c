/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:17:44 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/22 21:18:46 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_base(void)
{
	t_list	*tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp->number = -444;
	tmp->status = 1;
	tmp->next = 0;
	return (tmp);
}

void	roll_back(t_stack *a, int count)
{
	while (count > 0)
	{
		reverse_rotate(a);
		count--;
	}
}

bool	check_roll_back(t_stack *a, int b)
{
	t_list *tmp;

	tmp = a->list;
	if (tmp->status == 2 && a->roll == 0 && a->pin == 1)
	{
		b = a->pin;
		a->pin = 3;
		a->roll = 1;
		rotate(a);
		a->pin = b;
		tmp = a->rsp;
		return (false);
	}
	if (a->pin == 2)
	{
		while (tmp)
		{
			if (tmp->status == 1)
				return (true);
			tmp = tmp->next;
		}
		return (false);
	}
	return (true);
}

bool	check_rbp(t_stack *a)
{
	t_list *tmp;

	tmp = a->list;
	while (tmp)
	{
		if (tmp->status == 2)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}
