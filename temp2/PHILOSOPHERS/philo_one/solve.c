/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:36:24 by juyang            #+#    #+#             */
/*   Updated: 2021/03/23 16:36:25 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void				take_fork(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	if (philo->prog_ptr->system.finish == 0)
		print_state("has taken a fork", philo);
}

void				sleeping(t_philosopher *philo)
{
	if (philo->prog_ptr->system.finish == 0)
	{
		print_state("is Sleeping", philo);
		wait_time(get_time(), philo->time_to_sleep);
	}
}

void				eating(t_philosopher *philo)
{
	if (philo->prog_ptr->system.finish == 0)
	{
		philo->last_eat = get_time();
		print_state("is Eating", philo);
		wait_time(philo->last_eat, philo->time_to_eat);
		philo->eat_cnt++;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void				*solve(void *arg)
{
	t_philosopher	*philo;
	pthread_t		died_check;

	philo = (t_philosopher *)arg;
	philo->last_eat = get_time();
	pthread_create(&died_check, NULL, death_check, (void *)philo);
	pthread_detach(died_check);
	if (philo->index % 2 != 0)
		wait_time(get_time(), philo->time_to_eat);
	while (philo->prog_ptr->system.finish == 0)
	{
		take_fork(philo);
		eating(philo);
		sleeping(philo);
		if (philo->prog_ptr->system.finish == 0)
			print_state("is Thinking", philo);
		usleep(50);
	}
	return (NULL);
}
