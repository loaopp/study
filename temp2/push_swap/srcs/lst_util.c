/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:28:36 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/22 19:52:01 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*get_rbp(void)
{
	t_list	*tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (0);
	tmp->number = -999;
	tmp->status = 2;
	tmp->next = 0;
	return (tmp);
}

int			get_stack_size(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->status != 0)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_list		*check_what_ret(t_list *pp_tmp, t_list *p_tmp, t_stack *st)
{
	t_list *tmp;

	if (pp_tmp == 0 && p_tmp == 0)
		return (0);
	if (pp_tmp == 0 && p_tmp != 0)
	{
		tmp = pop(st);
	}
	else
	{
		tmp = p_tmp;
		pp_tmp->next = p_tmp->next;
		p_tmp->next = 0;
	}
	return (tmp);
}

t_list		*last_pop(t_stack *lst)
{
	t_list	*tmp;
	t_list	*p_tmp;
	t_list	*pp_tmp;

	tmp = lst->list;
	p_tmp = 0;
	pp_tmp = 0;
	while (tmp)
	{
		pp_tmp = p_tmp;
		p_tmp = tmp;
		tmp = tmp->next;
	}
	return (check_what_ret(pp_tmp, p_tmp, lst));
}

t_list		*mini_last(t_list *lst)
{
	t_list	*tmp;
	t_list	*p_tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->status == 2)
			break ;
		p_tmp = tmp;
		tmp = tmp->next;
	}
	return (p_tmp);
}
