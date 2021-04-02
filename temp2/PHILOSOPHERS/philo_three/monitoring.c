/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:24:32 by juyang            #+#    #+#             */
/*   Updated: 2021/03/28 16:24:34 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void				*full_check(void *arg)
{
	t_prog			*prog;
	int				full_cnt;

	prog = (t_prog *)arg;
	full_cnt = 0;
	while (1)
	{
		sem_wait(prog->system.status);
		if (prog->system.finish == 1)
			break ;
		full_cnt++;
		if (full_cnt == prog->system.number_of_philosophers
		&& prog->system.finish == 0)
		{
			sem_wait(prog->system.write);
			printf("All Philosophers are full\n");
			prog->system.finish = 1;
			sem_post(prog->system.write);
			sem_post(prog->system.finish_check);
			break ;
		}
		usleep(50);
	}
	return (NULL);
}

void				*death_check(void *arg)
{
	t_philosopher			*philo;

	philo = (t_philosopher *)arg;
	while (philo->status == ALIVE)
	{
		if ((get_time() - philo->last_eat) > philo->time_to_die
		&& philo->prog_ptr->system.finish == 0)
		{
			philo->prog_ptr->system.finish = 1;
			philo->status = DIED;
			sem_wait(philo->prog_ptr->system.write);
			ft_putnbr_fd(get_time() - philo->prog_ptr->system.start_time, 1);
			ft_putstr_fd("ms ", 1);
			ft_putnbr_fd(philo->index, 1);
			ft_putstr_fd(" is Died\n", 1);
			sem_post(philo->prog_ptr->system.finish_check);
		}
		usleep(50);
	}
	return (NULL);
}

void				wait_time(long long int save, long long int time_to)
{
	long long int	wait;

	while (get_time() < (save + time_to))
	{
		wait = (save + time_to - get_time()) * 1000 / 2;
		usleep(wait);
	}
}

void				*finish_check(void *arg)
{
	t_prog			*prog;
	int				i;

	i = -1;
	prog = (t_prog *)arg;
	usleep(50);
	sem_wait(prog->system.finish_check);
	sem_post(prog->system.status);
	prog->system.finish = 1;
	while (++i < prog->system.number_of_philosophers)
		kill(prog->philo[i].pid, SIGKILL);
	return ((void *)NULL);
}
