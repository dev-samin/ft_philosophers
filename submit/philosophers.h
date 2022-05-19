/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:08:09 by samin             #+#    #+#             */
/*   Updated: 2021/09/30 19:54:33 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_rule_info
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	int	eatting_done_count;
	int	death;
}				t_rule_info;

typedef struct s_philosopher
{
	int				philo_num;
	int				status;
	int				eating_count;
	long long		public_time;
	long long		eating_start_time;
	long long		starve_time;
	t_rule_info		*rule_info;
	pthread_t		philo_thread;
	pthread_t		monitor_thread;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_philosopher;

typedef struct s_philosophers_info
{
	t_philosopher	*philosopher;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_print;
	t_rule_info		*rule_info;
}				t_philosophers_info;

void		init(int argc, char **argv, t_philosophers_info *philosophers_info);
void		init_philosophers_info(t_philosophers_info *philosophers_info);
void		init_philosopher(t_philosophers_info *philosophers_info);
void		init_mutex(t_philosophers_info *philosophers_info);
void		init_thread(t_philosophers_info *philosophers_info);

void		*philosopher_action(t_philosopher *philo);
void		philosopher_eat(t_philosopher *philo);
void		philosopher_sleep(t_philosopher *philo);
void		philosopher_think(t_philosopher *philo);
void		take_fork(t_philosopher *philo, pthread_mutex_t *fork);

void		single_monitor(t_philosopher *philo);

long long	get_mstime(void);
void		philosopher_print(t_philosopher *philo, char *str);
void		check_str_num(int argc, char **str_num);
int			handle_one_philosopher(t_philosopher *philo);

int			ft_isdigit(int c);
void		ft_bzero(void *a, size_t len);
int			ft_atoi(const char *str);

#endif
