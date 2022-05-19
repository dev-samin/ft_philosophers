/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:08:09 by samin             #+#    #+#             */
/*   Updated: 2021/07/26 16:27:46 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include "libft/libft.h"

typedef struct s_rule_info
{
	int number_of_philosophers;
	int time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;

	int eatting_done_count;
	int death; 
}				t_rule_info;

typedef	struct	s_philosopher
{
	int				philo_num;
	int 			status; //필요할까? 죽었는지, 살았는지. 어떤 동작중인지도 필요한지?
	int 			eating_count;
	long long		public_time;
	long long		eating_start_time;
	long long		starve_time; //현재시간 - strat_eating_time
	t_rule_info 	*rule_info;
	pthread_t		thread;
	pthread_t		philo_thread;
	pthread_t		monitor_thread;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
}				t_philosopher;

typedef	struct	s_philosophers_info
{
	t_philosopher 	*philosopher;
	pthread_mutex_t *forks;
	pthread_mutex_t mutex_print;
	t_rule_info 	*rule_info;
}				t_philosophers_info;

void	check_str_num(char *str_num);
void	init(int argc, char **argv, t_philosophers_info *philosophers_info);
void	init_philosophers_info(t_philosophers_info *philosophers_info);
void	init_philosopher(t_philosophers_info *philosophers_info);
void	init_mutex(t_philosophers_info *philosophers_info);
void	init_thread(t_philosophers_info *philosophers_info);

long long get_mstime();

void	multi_monitor(t_philosophers_info *init_philosophers_info);

void	single_monitor(t_philosopher *philo);

void	*philosopher_action(t_philosopher *philo);

void	philosopher_eat(t_philosopher *philo);
void	philosopher_sleep(t_philosopher *philo);
void	philosopher_think(t_philosopher *philo);

void	take_fork(t_philosopher *philo, pthread_mutex_t *fork);

void	philosopher_print(t_philosopher *philo, char *str);

//argv 값 받기

#endif
