/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:01:45 by samin             #+#    #+#             */
/*   Updated: 2021/09/30 20:15:38 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init(int argc, char **argv, t_philosophers_info *philosophers_info)
{
	philosophers_info->rule_info->number_of_philosophers = ft_atoi(argv[1]);
	philosophers_info->rule_info->time_to_die = ft_atoi(argv[2]);
	philosophers_info->rule_info->time_to_eat = ft_atoi(argv[3]);
	philosophers_info->rule_info->time_to_sleep = ft_atoi(argv[4]);
	philosophers_info->rule_info->eatting_done_count = 0;
	philosophers_info->rule_info->death = 0;
	if (argc == 6)
		philosophers_info->rule_info->must_eat = ft_atoi(argv[5]);
	else
		philosophers_info->rule_info->must_eat = 0;
	if (philosophers_info->rule_info->number_of_philosophers == -1
		|| philosophers_info->rule_info->time_to_die == -1
		|| philosophers_info->rule_info->time_to_eat == -1
		|| philosophers_info->rule_info->time_to_sleep == -1
		|| philosophers_info->rule_info->must_eat == -1)
	{
		printf("over [int] range");
		exit(0);
	}
}

void	init_philosophers_info(t_philosophers_info *philosophers_info)
{
	philosophers_info->philosopher
		= malloc(sizeof(t_philosopher)
			* philosophers_info->rule_info->number_of_philosophers);
	philosophers_info->forks
		= malloc(sizeof(pthread_mutex_t)
			* philosophers_info->rule_info->number_of_philosophers);
	init_mutex(philosophers_info);
}

void	init_mutex(t_philosophers_info *philosophers_info)
{
	int	i;

	i = -1;
	while (++i < philosophers_info->rule_info->number_of_philosophers)
		pthread_mutex_init(&philosophers_info->forks[i], NULL);
	pthread_mutex_init(&philosophers_info->mutex_print, NULL);
}

void	init_philosopher(t_philosophers_info *philosophers_info)
{
	int	i;

	i = -1;
	while (++i < philosophers_info->rule_info->number_of_philosophers)
	{
		ft_bzero(&philosophers_info->philosopher[i], sizeof(t_philosopher));
		philosophers_info->philosopher[i].philo_num = i + 1;
		philosophers_info->philosopher[i].rule_info
			= philosophers_info->rule_info;
		philosophers_info->philosopher[i].mutex_print
			= &philosophers_info->mutex_print;
		philosophers_info->philosopher[i].left_fork
			= &philosophers_info->forks[i];
		philosophers_info->philosopher[i].right_fork
			= &philosophers_info->forks[(i + 1)
			% philosophers_info->rule_info->number_of_philosophers];
	}
}

void	init_thread(t_philosophers_info *philosophers_info)
{
	int			i;
	long long	public_time;

	i = -1;
	public_time = get_mstime();
	while (++i < philosophers_info->rule_info->number_of_philosophers)
	{
		philosophers_info->philosopher[i].public_time = public_time;
		philosophers_info->philosopher[i].eating_start_time = get_mstime();
		pthread_create(&philosophers_info->philosopher[i].philo_thread, NULL,
			(void *)philosopher_action, &philosophers_info->philosopher[i]);
		pthread_create(&philosophers_info->philosopher[i].monitor_thread, NULL,
			(void *)single_monitor, &philosophers_info->philosopher[i]);
		usleep(100);
	}
	i = -1;
	while (++i < philosophers_info->rule_info->number_of_philosophers)
	{
		pthread_join(philosophers_info->philosopher[i].philo_thread, NULL);
		pthread_join(philosophers_info->philosopher[i].monitor_thread, NULL);
	}
}
