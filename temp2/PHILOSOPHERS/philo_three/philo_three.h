/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:23:26 by juyang            #+#    #+#             */
/*   Updated: 2021/03/28 16:23:27 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>

# define ALIVE	0
# define FULL	1
# define DIED	2

typedef struct		s_system
{
	int				number_of_philosophers;
	int				finish;
	int				number_of_times_each_philosopher_must_eat;
	long long int	start_time;
	sem_t			*forks;
	sem_t			*status;
	sem_t			*write;
	sem_t			*finish_check;
}					t_system;

typedef struct		s_philosopher
{
	pid_t			pid;
	int				index;
	int				eat_cnt;
	long long int	last_eat;
	sem_t			*left_fork;
	sem_t			*right_fork;
	struct s_prog	*prog_ptr;
	int				status;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
}					t_philosopher;

typedef struct		s_prog
{
	t_philosopher	*philo;
	t_system		system;
}					t_prog;

int					prog_run(t_prog *prog);

int					argument_init(t_prog *prog, int argc, char **argv);
void				philosopher_init(t_prog *prog);
int					semaphore_init(t_prog *prog);

long long int		get_time(void);
int					ft_atoi(const char *str);
void				print_state(char *str, t_philosopher *philo);
int					ft_isdigit(int c);
void				clear(t_prog *prog);
void				ft_putnbr_fd(long long int n, int fd);

void				solve(void *arg);
void				sleeping(t_philosopher *philo);
void				take_fork(t_philosopher *philo);
void				eating(t_philosopher *philo);

void				*death_check(void *arg);
void				*full_check(void *arg);
int					full_cnt_check(t_prog *prog, int full_cnt);
void				wait_time(long long int save, long long int time_to);
void				*finish_check(void *arg);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);

#endif
