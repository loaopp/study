/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:57:00 by sanghpar          #+#    #+#             */
/*   Updated: 2021/03/22 19:28:09 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_digit(char *argv)
{
	char	*tmp;
	int		k;

	tmp = argv;
	while (*tmp)
	{
		k = *tmp;
		if (ft_isdigit(k) == 0)
		{
			return (0);
		}
		tmp++;
	}
	return (1);
}

int		check_digit(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (is_digit(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		dupli(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j <= argc - 1)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		checker(int argc, char **argv)
{
	t_stack	*st;
	t_stack	*st2;

	st = (t_stack *)malloc(sizeof(t_stack));
	st2 = (t_stack *)malloc(sizeof(t_stack));
	if (st == 0 || st2 == 0)
		return (0);
	set_struct(st, 1, 0);
	set_struct(st2, 2, 0);
	if (parse_number(argc, argv, st) == -1)
		return (3);
	push(st2, get_rbp());
	if (do_checker(st, st2) == 3)
		return (3);
	if (check_sort(st, st2) != 1)
		return (0);
	free_function(st, st2);
	return (1);
}

int		main(int argc, char **argv)
{
	char	**tmp;
	int		c;

	tmp = argv;
	if (argc <= 1)
		return (0);
	else
	{
		if (check_digit(argc, tmp) == 1 && dupli(argc, tmp) == 1)
		{
			c = checker(argc, tmp);
			if (c == 1)
				write(1, "OK\n", 3);
			else if (c == 0)
				write(1, "KO\n", 3);
			else if (c == 3)
				write(1, "Error\n", 6);
		}
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
