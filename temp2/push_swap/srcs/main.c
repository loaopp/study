/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:54:57 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/23 16:13:28 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack *st;
	t_stack *st2;

	st = (t_stack *)malloc(sizeof(t_stack));
	st2 = (t_stack *)malloc(sizeof(t_stack));
	if (st == 0 || st2 == 0)
		return (0);
	set_struct(st, 1, 1);
	set_struct(st2, 2, 1);
	if (argc >= 2)
	{
		if (parse_number(argc, argv, st) == -1)
		{
			write(1, "Error\n", 6);
		}
		else if (check_sort2(st) == 0)
		{
			if (mini_len(st) <= 5)
				push_swap2(st, st2);
			else
				push_swap(st, st2);
		}
		free_function(st, st2);
	}
	return (0);
}
