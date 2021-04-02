/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:13:13 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/22 21:14:18 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_stack_mid(t_stack *st)
{
	int		*arr;
	int		size;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = st->list;
	size = mini_len(st);
	arr = (int *)malloc(size * sizeof(int));
	while (tmp)
	{
		arr[i] = tmp->number;
		i++;
		tmp = tmp->next;
		if (i == size)
			break ;
	}
	i = get_sort_mid(arr, size);
	free(arr);
	return (i);
}

int		get_sort_mid(int *arr, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (*(arr + i) > *(arr + j))
			{
				tmp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = tmp;
			}
			j++;
		}
		i++;
	}
	return (*(arr + (size / 2)));
}

void	send_a_to_b(t_stack *a, t_stack *b, int mid, int len)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	tmp = a->list;
	tmp2 = 0;
	i = 0;
	while (len > 0)
	{
		tmp2 = tmp->next;
		if (tmp->number < mid)
			push_a_to_b(a, b);
		else
		{
			i++;
			rotate(a);
		}
		tmp = tmp2;
		len--;
	}
	if (check_roll_back(a, 3))
		roll_back(a, i);
}

void	divide_stack(t_stack *a, t_stack *b)
{
	int stack_len;

	stack_len = mini_len(a);
	if (stack_len > 3)
	{
		push(b, get_base());
		send_a_to_b(a, b, get_stack_mid(a), stack_len);
	}
}
